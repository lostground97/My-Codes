#include <bit/stdc++.h>
using namespace std;
 
int solve(int n, int k)
{
  if (n == 1)
    return 1;
  else
    return (solve(n - 1, k) + k-1) % n + 1;
}

int main()
{
    while(1)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        if(n==0 and k==0)
            break;
        printf("%d %d %d\n",n,k, solve(n, k));
    }
  return 0;
}
