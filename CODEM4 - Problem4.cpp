#include <bits/stdc++.h>
using namespace std;

int arr[31];
int dp[31][31];
int dp2[31][31];

void init()
{
    for(int i=0; i<31; i++)
    {
        for(int j=0; j<31; j++)
        {
            dp[i][j] = -1;
            dp2[i][j] = -1;
        }
    }
}

int solve(int s, int e)
{
    if(e<s)
        return 0;
    if(s==e)
    {
        dp[s][e] = arr[s];
        return dp[s][e];
    }
    if(dp[s][e]!=-1)
        return dp[s][e];
    dp[s][e] = max(arr[s]+min(solve(s+2,e),solve(s+1,e-1)),arr[e]+min(solve(s,e-2),solve(s+1,e-1)));
    return dp[s][e];
}

int dumbp(int s, int e)
{
    if(s>e)
        return 0;
    if(s==e)
    {
        dp2[s][e] = arr[s];
        return arr[s];
    }
    if(dp2[s][e]!=-1)
        return dp2[s][e];
    dp2[s][e] = max(arr[s]+max(dumbp(s+2,e),dumbp(s+1,e-1)),arr[e]+max(dumbp(s,e-2),dumbp(s+1,e-1)));
    return dp2[s][e];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        init();
        int n;
        cin>>n;
        for(int i=1; i<=n; i++)
            cin>>arr[i];
        int dumb = dumbp(1,n);
        int ans = solve(1,n);
        cout<<dumb<<" ";
        cout<<ans<<endl;
    }
    return 0;
}
