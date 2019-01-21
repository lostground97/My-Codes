//Some random shit goes here. I don't know why.

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define in insert
#define mod 1000000007
#define vi vector< ll >
#define vpair vector< pair <ll,ll> >
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define endl "\n"
#define cpx complex<double>
#define pi 3.14159265359

int level[10005];
bool mark[10005];
vector<int> adj[10005];

void init()
{
    memset(level,INT_MAX,sizeof(level));
    memset(mark,false,sizeof(mark));
    for(int i=0; i<10005; i++)
        adj[i].clear();
    return;
}

void bfs(int n)
{
    mark[n] = true;
    queue<int> q;
    q.push(n);
    while(q.size()!=0)
    {
        int p = q.front();
        q.pop();
        for(int i=0; i<adj[p].size(); i++)
        {
            if(mark[adj[p][i]]==false)
            {
                q.push(adj[p][i]);
                level[adj[p][i]] = 1 + level[p];
                mark[adj[p][i]] = true;
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    init();
	    int m;
	    cin>>m;
	    for(int i=0; i<m; i++)
	    {
	        int x, y;
	        cin>>x>>y;
	        adj[x].pb(y);
	        adj[y].pb(x);
	    }
	    level[1] = 0;
	    bfs(1);
	    cout<<level[n]<<endl;
	}
}
