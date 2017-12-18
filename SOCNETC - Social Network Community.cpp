#include <bits/stdc++.h>
using namespace std;

int dis[100002];
int cap[100002];

void init()
{
    for(int i=0; i<100002; i++)
    {
        dis[i] = i;
        cap[i] = 1;
    }
}

int root(int x)
{
    while(dis[x]!=x)
    {
        x = dis[x];
        dis[x] = dis[dis[x]];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    if(cap[q]>cap[p])
    {
        dis[p] = dis[q];
        cap[q] = cap[q] + cap[p];
    }
    else
    {
        dis[q] =dis[p];
        cap[p] = cap[p] + cap[q];
    }
}

void merge(int x, int y)
{
    int p = root(x);
    int q = root(y);
    cap[p] = cap[p] + cap[q];
    cap[q] = cap[p];
}

int main(void)
{
    init();
    int n, m;
    cin>>n>>m;
    int q;
    cin>>q;
    while(q--)
    {
        char in;
        cin>>in;
        if(in=='A')
        {
            int x, y;
            cin>>x>>y;
            int p = root(x);
            int q = root(y);
            if(p!=q)
            {
                if(cap[p]+cap[q]>m)
                {
                    
                }
                else
                {
                    union1(x,y);
                }
            }
            else
            {
                union1(x,y);
            }
        }
        if(in=='S')
        {
            int x;
            cin>>x;
            int size = cap[root(x)];
            cout<<size<<endl;
        }
        if(in=='E')
        {
            int x, y;
            cin>>x>>y;
            int p = root(x);
            int q = root(y);
            if(p==q)
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
    }
    return 0;
}
