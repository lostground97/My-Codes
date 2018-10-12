//Rishabh Sethi @lostground97

#include <bits/stdc++.h>
using namespace std;

int dp[1002];

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n, k;
    scanf("%d%d",&n,&k);
    int arr[k+1];
    for(int i=1; i<=k; i++)
    {
      scanf("%d",&arr[i]);
    }
    for(int i=1; i<=k; i++)
        dp[i] = arr[i];
    for(int i=2; i<=k; i++)
    {
        for(int j=1; j<i; j++)
        {
            if(arr[i-j]==-1 or dp[j]==-1)
                continue;
            if(dp[i]==-1)
            {
                dp[i] = arr[j] + dp[i-j];
            }
            else
            {
                dp[i] = min(dp[i],dp[j]+arr[i-j]);
            }
        }
    }
    if(k==0)
        printf("0\n");
    else
        printf("%d\n",dp[k]);
  }
}
