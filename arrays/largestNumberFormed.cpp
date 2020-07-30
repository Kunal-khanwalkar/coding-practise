#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



bool compare(string x, string y)
{
	string xy = x.append(y);
	string yx = y.append(x);

	return xy.compare(yx);
}

void printLargest(vector<string> arr)
{
	sort(arr.begin(), arr.end(), compare);

	for(int i=0;i<arr.size();i++)
		cout<<arr[i];
}


int main()
{
	vector<string> arr;
	arr.push_back("54");
	arr.push_back("546");
	arr.push_back("548");
	arr.push_back("60");

	printLargest(arr);

	return 0;
}