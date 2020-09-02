#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;



bool parenthesisCheck(string expr)
{
	stack<char> s;
	char x;

	for(int i=0;i<expr.length();i++)
	{
		if(expr[i] == '(' || expr[i] == '{' || expr[i] == '[')		
			s.push(expr[i]);					

		else if(expr[i] == ')')
		{
			x = s.top();
			s.pop();

			if(x!='(')
				return false;
		}
		else if(expr[i] == '}')
		{
			x = s.top();
			s.pop();

			if(x!='{')
				return false;
		}
		else if(expr[i] == ']')
		{
			x = s.top();
			s.pop();

			if(x!='[')
				return false;
		}
	}

	return (s.empty());
}



bool hashing(string expr)
{
	unordered_map<char,int> mp;

	for(int i=0;i<expr.length();i++)
	{
		if(expr[i] == '(' || expr[i] == '{' || expr[i] == '[')		
			mp[expr[i]]++;		

		if(expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
			mp[expr[i]]--;		
	}

	for(auto itr=mp.begin(); itr!=mp.end(); itr++)
		if(itr->second != 0)
			return false;

	return true;
}



int main()
{
	string expr = "{a+(b*c)}+[d]";

	if(parenthesisCheck(expr))
		cout<<"\nCorrect";
	else
		cout<<"\nIncorrect";

	return 0;
}