#include<iostream>
using namespace std;


int value(char r)
{
	if(r=='I')
		return 1;
	if(r=='V')
		return 5;
	if(r=='X')
		return 10;
	if(r=='L')
		return 50;
	if(r=='C')
		return 100;
	if(r=='D')
		return 500;
	if(r=='M')
		return 1000;	
	return -1;
}



int romanToDecimal(string s)
{
	int res = 0;
	int n = s.length();

	for(int i=0;i<n;i++)
	{
		int s1 = value(s[i]);

		if(i+1 < n)
		{
			int s2 = value(s[i+1]);
			if(s1 >= s2)
				res += s1;
			else
			{
				res += s2-s1;
				i++;
			}

		}
		else
			res += s1;
	}
	return res;
}




string decimalToRoman(int number)
{
	string rom;
	int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
	string val[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
	int i = 12;

	while(number>0)
	{
		int div = number/num[i];
		number = number % num[i];
		while(div > 0)
		{
			rom.append(val[i]);			
			div--;
		}
		i--;
	}	
	return rom;
}


int main()
{
	string s = "MCMIV";
	cout<<romanToDecimal(s)<<'\n';

	int number = 3549;
	cout<<decimalToRoman(number);

	return 0;
}