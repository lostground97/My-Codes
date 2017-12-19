#include <bits/stdc++.h>
using namespace std;

vector<pair<long long int,int>> adj[1000000];
bool bool_arr[1000000];

void init()
{
  for(int i=0; i<1000000; i++)
  {
    adj[i].clear();
    bool_arr[i] = false;
  }
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    init();
    int flag = 0;
    int n, m;
    scanf("%d%d",&n,&m);
    int arr[n+1];
    priority_queue <pair<long long int,int> > pq;
    for(int i=1; i<=n; i++)
      scanf("%d",&arr[i]);
    for(int i=1; i<=m; i++)
    {
      long long int c;
      int u, v;
      scanf("%d%d%lld",&u,&v,&c);
      adj[u].push_back(make_pair(c,v));
      adj[v].push_back(make_pair(c,u));
    }
    for(int i=1; i<=n; i++)
    {
      if(arr[i]==1)
      {
        bool_arr[i] = true;
        for(int j=0; j<adj[i].size(); j++)
          pq.push(make_pair(-adj[i][j].first,adj[i][j].second));
      }
    }
    long long int ans = 0;
    while(pq.empty()!=true)
    {
      pair<long long int, int> temp = pq.top();
      pq.pop();
      long long int cost = temp.first;
      int id = temp.second;
      if(bool_arr[id]==false)
      {
        bool_arr[id] = true;
        ans = ans - cost;
        for(int i=0; i<adj[id].size(); i++)
        {
            pq.push(make_pair(-adj[id][i].first,adj[id][i].second));
        }
      }
    }
    for(int i=1; i<=n; i++)
    {
      if(bool_arr[i]==false)
        flag = 1;
    }
    if(flag==1)
      printf("impossible\n");
    else
      printf("%lld\n",ans);
  }
  return 0;
}
