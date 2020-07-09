#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;



void sorting(string str1, string str2)
{
	if(str1.length() != str2.length())
	{
		cout<<"\nNot anagrams";
		return;
	}

	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	for(int i=0;i<str1.length();i++)
		if(str1[i] != str2[i])
		{
			cout<<"\nNot anagrams";
			return;
		}
	cout<<"\nStrings are anagrams";
}



void hashing(string str1, string str2)
{

	if(str1.length() != str2.length())
	{
		cout<<"\nNot anagrams";
		return;
	}


	unordered_map<char,int> mp;

	for(int i=0;i<str1.length();i++)
	{
		mp[str1[i]]++;
		mp[str2[i]]--;
	}

	for(auto itr=mp.begin();itr!=mp.end();itr++)
		if(itr->second != 0)
		{
			cout<<"\nNot anagrams";
			return;
		}

	cout<<"\nStrings are anagrams";
}




int main()
{
	string str1 = "listen";
	string str2 = "silent";

	//sorting(str1,str2);
	hashing(str1,str2);

	return 0;
}