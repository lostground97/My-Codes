#include <stdio.h>

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a , b ;
        scanf("%d%d",&a,&b);
        int c , d ;
        c = rev(a);
        d = rev(b);
        int ans , ans_rev;
        ans = c + d;
        ans_rev = rev(ans);
        printf("%d\n",ans_rev);
    }
    return 0;
}

int rev(int n)
{
    int i , j=0 ;
    while(n>0)
    {
        i = n % 10;
        j = j*10 + i;
        n = n / 10;
    }
    return j;
}
