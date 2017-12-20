#include <bits/stdc++.h>
using namespace std;

vector<int> adj[2002];
bool bool_arr[2002];
int color[2002];

void init()
{
     for(int i=0; i<2002; i++)
     {
          adj[i].clear();
          bool_arr[i] = false;
          color[i] = -1;
     }
}

bool check(int n)
{
     queue<int> q;
     q.push(n);
     color[n] = 1;
     while(q.empty()!=true)
     {
          int x = q.front();
          q.pop();
          bool_arr[x] = true;
          for(int i=0; i<adj[x].size(); i++)
          {
               if(color[x]==color[adj[x][i]])
               {
                    return false;
               }
               else
               {
                    if(bool_arr[adj[x][i]]==false)
                    {
                       if(color[x]==1)
                       {
                            color[adj[x][i]] = 2;
                       }
                       else
                       {
                            color[adj[x][i]] = 1;
                       }
                       bool_arr[adj[x][i]] = true;
                       q.push(adj[x][i]);
                    }
               }
          }
     }
     return true;
}

bool coloring(int n)
{
     for(int i=1; i<=n; i++)
     {
          if(bool_arr[i]==false)
          {
               bool ans = check(i);
               if(ans==false)
                    return false;
          }
     }
     return true;
}

int main(void)
{
     int t;
     scanf("%d",&t);
     for(int z=1; z<=t; z++)
     {
          init();
          int n, m;
          scanf("%d%d",&n,&m);
          for(int i=0; i<m; i++)
          {
               int u, v;
               scanf("%d%d",&u,&v);
               adj[u].push_back(v);
               adj[v].push_back(u);
          }
          bool nn = coloring(n);
          if(nn==true)
          {
               printf("Scenario #%d:\nNo suspicious bugs found!\n",z);
          }
          else
          {
               printf("Scenario #%d:\nSuspicious bugs found!\n",z);
          }
     }
     return 0;
}
