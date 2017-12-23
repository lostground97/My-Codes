#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	while(1)
	{
		long long int n;
		scanf("%lld",&n);
		if(n==0)
			break;
		long long int arr[n],work=0;
		for(long long int i=0; i<n; i++)
		{
			scanf("%lld",&arr[i]);
			if(i>0)
			{
				work = work + abs(arr[i-1]);
				arr[i] = arr[i] + arr[i-1];
			}
		}
		printf("%lld\n",work);
	}
	return 0;
}
