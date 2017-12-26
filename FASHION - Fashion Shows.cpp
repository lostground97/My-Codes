#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int arr[n],brr[n];
        for(int i=0; i<n; i++)
            scanf("%d",&arr[i]);
        for(int i=0; i<n; i++)
            scanf("%d",&brr[i]);
        sort(arr,arr+n);
        sort(brr,brr+n);
        long long int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum = sum + (arr[i]*brr[i]);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
