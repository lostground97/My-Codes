#include <bits/stdc++.h>
using namespace std;

pair<int,int> p[5005];
long long int dp[10005];

void init()
{
    for(int i=0; i<=10005; i++)
    {
        dp[i] = 0;
        weight[i] = 0;
    }
}

long long int min(long long int a,long long int b)
{
    if(a<=b)
        return a;
    return b;
}

void solve(long long int w,long long int n)
{
    for(int j=0; j<=w; j++)
    {
        for(int i=1; i<=n; i++)
        {
            long long int a = p[i].first;
            long long int b = p[i].second;
            if(b==j || dp[j-b]>0)
            {
                if(dp[j]!=0)
                    dp[j] = min(dp[j],a + dp[j-b]);
                else
                    dp[j] = a + dp[j-b];
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        init();
        long long int a, b;
        scanf("%lld%lld",&a,&b);
        long long int wt = abs(b-a);
        long long int n;
        scanf("%lld",&n);
        for(long long int i=1; i<=n; i++)
        {
            long long int x, y;
            scanf("%lld%lld",&x,&y);
            p[i] = make_pair(x,y);
        }
        solve(wt,n);
        if(dp[wt]==0)
        {
            printf("This is impossible.\n");
        }
        else
        {
            printf("The minimum amount of money in the piggy-bank is %lld.\n",dp[wt]);
        }
    }
    return 0;
}
