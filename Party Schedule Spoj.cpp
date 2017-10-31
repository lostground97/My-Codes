#include <bits/stdc++.h>
using namespace std;

int mat[2002][2001];
int weight[2002][2001];
pair<int,int> p[2002];

int max(int a, int b)
{
    if(a>=b)
        return a;
    return b;
}

void solve(int w, int n)
{
    for(int i=0; i<=w; i++)
    {
        mat[0][i] = 0;
    }
    for(int i=0; i<=n; i++)
    {
        mat[i][0] = 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=w; j++)
        {
            int a = p[i].first;
            int b = p[i].second;
            if(a>j)
            {
                weight[j][i] = weight[j][i-1];
                mat[j][i] = mat[j][i-1];
            }
            else
            {
                int xx = mat[j][i-1];
                int yy = b + mat[j-a][i-1];
                mat[j][i] = max(xx,yy);
                if(xx>yy)
                {
                    weight[j][i] = weight[j][i-1];
                }
                else
                {
                    if(xx==yy)
                    {
                        weight[j][i] = abs(max(-weight[j][i-1],-(a + weight[j-a][i-1])));
                    }
                    else
                    {
                        weight[j][i] = a + weight[j-a][i-1];
                    }
                }
            }
        }
    }
}

int main(void)
{
    while(1)
    {
        int w, n;
        scanf("%d%d",&w,&n);
        if(w==0 && n==0)
            break;
        for(int i=1; i<=n; i++)
        {
            int x, y;
            scanf("%d%d",&x,&y);
            p[i] = make_pair(x,y);
        }
        solve(w,n);
        printf("%d %d\n",weight[w][n],mat[w][n]);
    }
    return 0;
}
