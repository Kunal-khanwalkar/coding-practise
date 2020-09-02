#include<iostream>
using namespace std;



string removeUtil(string str, char &last_removed)
{
	if(str.length() == 0 || str.length() == 1)
		return str;

	if(str[0] == str[1])
	{
		last_removed = str[0];
		while(str.length() > 1 && str[0] == str[1])
			str = str.substr(1,str.length());
		str = str.substr(1,str.length());
		return removeUtil(str,last_removed);
	}

	string rem_str = removeUtil(str.substr(1,str.length()),last_removed);

	if(rem_str.length() != 0 && rem_str[0] == str[0])
	{
		last_removed = str[0];
		return rem_str.substr(1,rem_str.length());
	}

	if(rem_str.length() == 0 && last_removed == str[0])
		return rem_str;

	return (str[0] + rem_str);
}

string remove(string str)
{
	char last_removed='\n';
	return removeUtil(str, last_removed);
}



int main()
{
	string str = "geeksforgeeg";
	cout<<remove(str);

	return 0;
}