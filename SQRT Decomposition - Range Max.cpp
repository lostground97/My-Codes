#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n , q;
    scanf("%d%d",&n,&q);
    int m = sqrt(n);
    int p = ceil(sqrt(n));
    int arr[n] , sum[p]={0};
    int k=-1;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
        if(i%m==0)
        {
            k++;
        }
        sum[k] = sum[k] + arr[i];
    }
    while(q--)
    {
        int type;
        scanf("%d",&type);
        if(type==1)
        {
            int l ,r;
            scanf("%d%d",&l,&r);
            int ans = 0;
            while(l<r && l%m!=0 && l!=0)
            {
                ans = ans + arr[l];
                l++;
            }
            while(l+m<=r)
            {
                ans = ans + sum[l/m];
                l = l + m;
            }
            while(l<=r)
            {
                ans = ans + arr[l];
                l++;
            }
            printf("%d\n",ans);
        }
        if(type==2)
        {
            int index, change;
            scanf("%d%d",&index,&change);
            sum[index/m] = sum[index/m] - arr[index] + change;
            arr[index] = change;
        }
    }
    return 0;
}
