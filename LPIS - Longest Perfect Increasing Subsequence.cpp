#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n;
	cin>>n;
	int i, arr[n];
	for (i = 0; i < n; i++) 
	{
		cin>>arr[i];
	}
	int ans[n],brr[100005];
	for (i = 0; i < n; i++) 
	{
		ans[i] = 1+brr[arr[i]-1];
		brr[arr[i]] = ans[i];
	}
	int ans1 = 0;
	for (i = 0; i < n; i++) 
	{
		ans1 = max(ans1, ans[i]);
	}
	cout<<ans1<<endl;
	return 0;
}
