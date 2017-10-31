#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
bool bool_arr[100001];
int level[100001];

void init()
{
    for(int i=0; i<100001; i++)
    {
        bool_arr[i] = false;
    }
}

int find_marker(int n)
{
    bool_arr[n] = true;
    queue<int> q;
    q.push(n);
    int p;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        for(int i = 0;i < adj[ p ].size() ; i++)
        {
            if(bool_arr[adj[ p ][ i ] ] == false)
            {
                q.push(adj[ p ][ i ]);
                bool_arr[adj[ p ][ i ] ] = true;
            }
        }
    }
    return p;
}

void ans(int s) {
    queue <int> q;
    q.push(s);
    level[ s ] = 0 ;  //Setting the level of the source node as 0
    bool_arr[ s ] = true;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(int i = 0;i < adj[ p ].size() ; i++)
        {
            if(bool_arr[ adj[ p ][ i ] ] == false)
            {
                level[ adj[ p ][ i ] ] = level[ p ]+1;                 
                q.push(adj[ p ][ i ]);
                bool_arr[ adj[ p ][ i ] ] = true;
            }
        }
    }
}

int main()
{
    init();
    int n;
    scanf("%d",&n);
    for(int i=1; i<n; i++)
    {
        int x, y;
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int max = find_marker(n);
    init();
    ans(max);
    sort(level,level+n+1);
    cout<<level[n]<<endl;
    return 0;
}
