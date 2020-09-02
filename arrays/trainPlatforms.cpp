#include<iostream>
#include<algorithm>
using namespace std;


int findPlatform(int *arr, int *dep, int n)
{
	sort(arr,arr+n);
	sort(dep,dep+n);

	int plat_cnt = 1, res = 1;
	int i=1,j=0;

	while(i<n && j<n)
	{
		if(arr[i] <= dep[j])
		{
			plat_cnt++;
			i++;
		}
		else if(arr[i] > dep[j])
		{
			plat_cnt--;
			j++;
		}
		if(plat_cnt > res)
			res = plat_cnt;
	}

	return res;
}	


int main()
{
	int arr[] = { 900, 940, 950, 1100, 1500, 1800 }; 
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 }; 
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum Number of Platforms Required = "
         << findPlatform(arr, dep, n); 

	return 0;
}