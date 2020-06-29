#include<iostream>
#include<algorithm>
using namespace std;


void stlmethod(string s)
{
	bool val = next_permutation(s.begin(), s.end());

	if(val == false)
		cout<<"\nNot possible\n";
	else
		cout<<s<<endl;
}


int bsearch(string& s, int l, int r, int key) 
{ 
    int index = -1; 
    while (l <= r) { 
        int mid = l + (r - l) / 2; 
        if (s[mid] <= key) 
            r = mid - 1; 
        else { 
            l = mid + 1; 
            if (index == -1 || s[index] >= s[mid]) 
                index = mid; 
        } 
    } 
    return index; 
} 


bool nextperm(string &s)
{
	int len = s.length(), i = len-2;
	while(s[i]>=s[i+1] && i>=0)
		i--;
	if(i<0)
		return false;

	int index = bsearch(s, i+1, len-1, s[i]);
	swap(s[i],s[index]);

	while(i+1 < len-1)
		swap(s[i++ + 1], s[len-- - 1]);

	return true;
}

void mymethod(string s)
{
	bool val = nextperm(s);
	if(val == false)
		cout<<"\nNot possible\n";
	else
		cout<<s<<endl;	
}


int main()
{
	string s = {"abedc"};
	
	//stlmethod(s);
	mymethod(s);

	return 0;
}	