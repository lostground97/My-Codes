#include <bits/stdc++.h>
using namespace std;

int color[100005];
vector<int> adj[100005];
bool bool_arr[100005];

void coloring(int n)
{
    color[n] = 1;
 
    queue <int> q;
    q.push(n);
    bool_arr[n] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v <adj[u].size(); ++v)
        {
            if(bool_arr[adj[u][v]]==false)
            {
                bool_arr[adj[u][v]] = true;
                if(color[u]==1)
                    color[adj[u][v]] = 0;
                else
                    color[adj[u][v]] = 1;
                q.push(adj[u][v]);
            }
        }
    }
}

int main()
{
    memset(bool_arr,false,sizeof(bool_arr));
    memset(color,-1,sizeof(color));
    int n;
    cin>>n;
    long long int c1 = 0, c2 = 0;
    int x, y;
    for(int i=1; i<n; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    coloring(1);
    for(int i=1; i<=n; i++)
    {
        if(color[i]==1)
            c1++;
        if(color[i]==0)
            c2++;
    }
    long long int ans = c1*c2-(n-1);
    cout<<ans<<endl;
    return 0;
}
