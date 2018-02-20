#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        int n;
        cin>>n;
        long long int arr[n+1];
        for(int i=1; i<=n; i++)
            scanf("%lld",&arr[i]);
        long long int dp[n+1];
        dp[0] = 0;
        dp[1] = arr[1];
        for(int i=2; i<=n; i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+arr[i]);
        }
        cout<<"Case "<<k<<": "<<dp[n]<<endl;
    }
    return 0;
}
