#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;




void bruteForce(string str)
{
	int cnt = 0;	
	int i,j;

	while(str.length())
	{
		int l = str.length();
		int flag = 0;

		for(i=0,j=l-1; i<=j; i++,j--)
			if(str[i]!=str[j])
			{	
				flag = 1;			
				break;
			}		
		if(flag == 0)
		{
			cout<<cnt;
			return;
		}
		else
		{
			cnt++;
			str.erase(str.begin() + str.length() - 1);
		}
	}
}



vector<int> computeLps(string str)
{
	int M = str.length();
	vector<int> lps(M);

	int len = 0;
	lps[0] = 0;

	int i = 1;
	while(i < M)
	{
		if(str[i] == str[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if(len!=0)
				len = lps[len-1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}

	return lps;
}




void lpsMethod(string str)
{
	string revStr = str;
	reverse(revStr.begin(), revStr.end());
	string concat = str + "$" + revStr;

	vector<int> lps = computeLps(concat);

	cout<<str.length() - lps.back();
}


int main()
{
	string str = "BABABAA";
	
	//bruteForce(str);

	lpsMethod(str);

	return 0;
}