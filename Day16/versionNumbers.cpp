#include<iostream>
#include<vector>
#include<sstream>
using namespace std;


void checkVersions(string str1, string str2)
{
	vector<string> tokens1;
	vector<string> tokens2;	
	string temp;

	stringstream check1(str1);
	while(getline(check1,temp,'.'))
		tokens1.push_back(temp);

	stringstream check2(str2);
	while(getline(check2,temp,'.'))
		tokens2.push_back(temp);

	int n = min(tokens1.size(),tokens2.size());	

	for(int i=0;i<n;i++)
	{
		if(tokens1[i] > tokens2[i])
		{
			cout<<"Version1 is latest";
			return;
		}
		else if(tokens1[i] < tokens2[i])
		{
			cout<<"Version2 is latest";
			return;	
		}
	}

	if(tokens1.size() > tokens2.size())
		cout<<"Version1 is latest";
	else if(tokens1.size() < tokens2.size())
		cout<<"Version2 is latest";
	else
		cout<<"Both versions are same";
}



int main()
{
	string str1 = "1.0.7.3";
	string str2 = "1.0.7";

	checkVersions(str1,str2);

	return 0;
}