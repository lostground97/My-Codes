#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    scanf("%d%d",&n,&k);
    int arr[n];
    for(int i=0; i<=n; i++)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    int count=0;
    for(int i=0; i<n; i++)
    {
        if(binary_search(arr,arr+n,arr[i]+k))
            count++;
    }
    printf("%d\n",count);
    return 0;
}
