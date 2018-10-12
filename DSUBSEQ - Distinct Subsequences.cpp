//Rishabh Sethi @lostground97

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long int solve(string &str)
{
    int n = str.size();
    long long int dp[n+1] = {0};
    vector<int> last_occ(256,-1);
    dp[0] = 1;
    for(int i=1; i<=n; i++)
    {
        dp[i] = (2%MOD*dp[i-1]%MOD)%MOD;
        if(last_occ[str[i-1]]!=-1)
        {
            dp[i] = ((dp[i]%MOD - dp[last_occ[str[i-1]]]%MOD)+ MOD)%MOD;
        }
        last_occ[str[i-1]] = i-1;
    }
    return dp[n];
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string str;
        cin>>str;
        long long int ans = solve(str);
        printf("%lld\n",ans);
    }
    return 0;
}
