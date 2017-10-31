#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000002];
bool bool_arr[1000002];
int id[1002][1002];
int dis[1000002];

void dfs(int n)
{
    bool_arr[n] = true;
    for(int i=0; i<adj[n].size(); i++)
    {
        if(bool_arr[adj[n][i]]==false)
        {
            dfs(adj[n][i]);
        }
    }
}

void init(int n, int m)
{
    for(int i=0; i<1000002; i++)
    {
        bool_arr[i] = false;
    }
    int count = 1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            id[i][j] = count;
            count ++;
        }
    }
}

int main()
{
    int n1, m;
    scanf("%d%d",&n1,&m);
    init(n1,m);
    int count =0;
    string str[n1+1];
    int s, n, w, e;
    int flag1=0, flag2=0;
    for(int i=1; i<=n1; i++)
    {
        cin>>str[i];
    }
    int i = 1;
    for(int j=0; j<m; j++)
    {
        if(str[i][j]=='N')
        {
            n = 1;
            s = -1;
            flag1 = 1;
            break;
        }
        if(str[i][j]=='S')
        {
            s = 1;
            n = -1;
            flag1 = 1;
            break;
        }
    }
    i = n1;
    if(flag1==0)
    {
        for(int j=0; j<m; j++)
        {
            if(str[i][j]=='N')
            {
                n = -1;
                s = 1;
                flag1 = 1;
                break;
            }
            if(str[i][j]=='S')
            {
                s = -1;
                n = 1;
                flag1 = 1;
                break;
            }
        }
    }
    i = 0;
    for(int j=0; j<n1; j++)
    {
        if(str[j][i]=='E')
        {
            e = 1;
            w = -1;
            flag2 = 1;
            break;
        }
        if(str[j][i]=='W')
        {
            w = 1;
            e = -1;
            flag2 = 1;
            break;
        }
    }
    i = m-1;
    if(flag2==0)
    {
        for(int j=0; j<n1; j++)
        {
            if(str[j][i]=='E')
            {
                e = -1;
                w = 1;
                flag2 = 1;
                break;
            }
            if(str[j][i]=='W')
            {
                w = -1;
                e = 1;
                flag2 = 1;
                break;
            }
        }
    }
    for(int i=1; i<=n1; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char x = str[i][j-1];
            if(x=='S')
            {
                adj[id[i][j]].push_back(id[i+s][j]);
                adj[id[i+s][j]].push_back(id[i][j]);
            }
            if(x=='N')
            {
                adj[id[i][j]].push_back(id[i+n][j]);
                adj[id[i+n][j]].push_back(id[i][j]);
            }
            if(x=='E')
            {
                adj[id[i][j]].push_back(id[i][j+e]);
                adj[id[i][j+e]].push_back(id[i][j]);
            }
            if(x=='W')
            {
                adj[id[i][j]].push_back(id[i][j+w]);
                adj[id[i][j+w]].push_back(id[i][j]);
            }
        }
    }
    count =0;
    for(int i=1; i<=n1*m; i++)
    {
        if(bool_arr[i]==false)
        {
            dfs(i);
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
