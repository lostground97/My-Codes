#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000000];
bool bool_arr[1000000];

void init()
{
    for(int i=0; i<1000000; i++)
        bool_arr[i] = false;
}

void dfs(int n)
{
    bool_arr[n] = true;
    for(int i=0; i<adj[n].size(); i++)
    {
        if(bool_arr[adj[n][i]]==false)
            dfs(adj[n][i]);
    }
}

int main()
{
    init();
    int n, m;
    scanf("%d%d",&n,&m);
    int flag = 0;
    for(int i=0; i<m; i++)
    {
        int x, y;
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(m+1==n)
    {
        flag = 1;
    }
    if(flag==1)
    {
        int c = 0;
        for(int i=1; i<=n; i++)
        {
            if(bool_arr[i]==false)
            {
                dfs(i);
                c++;
            }
        }
        if(c!=1)
            flag=0;
    }
    if(flag==0)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}
