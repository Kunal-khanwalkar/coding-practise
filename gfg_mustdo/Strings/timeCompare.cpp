#include<iostream>
#include<vector>
using namespace std;


void digitsRepeat(string str1, string str2)
{
	vector<int> nums(10,0);

	for(int i=0;i<str1.length();i++)
	{
		if(isdigit(str1[i]))
			nums[(int)(str1[i] - '0')]++;			
		
		if(isdigit(str2[i]))
			nums[(int)(str2[i] - '0')]++;					
	}

	for(int i=0;i<10;i++)
		cout<<nums[i]<<' ';
}



int main()
{
	string str1 = "23:00:00";
	string str2 = "23:00:01";

	digitsRepeat(str1,str2);

	return 0;
}