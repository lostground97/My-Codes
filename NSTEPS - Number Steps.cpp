#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int u , v;
        scanf("%d%d",&u,&v);
        if(u==v || (u-v)==2)
        {
            int a = u+v;
            if(u%2==0 && v%2==0)
            {
                printf("%d\n",a);
            }
            else
            {
                printf("%d\n",a-1);
            }
        }
        else
        {
            printf("No Number\n");
        }
    }
    return 0;
}
