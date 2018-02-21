#include <bits/stdc++.h>
using namespace std;

int main()
{
    int seive[10002] = {0};
    for(int i=2; i<=10001; i++)
    {
        if(seive[i]==0)
        {
            for(int j=2*i; j<10002; j=j+i)
            {
                seive[j] = 1;
            }
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int mark[10002];
        memset(mark,0,sizeof(mark));
        int n, m;
        cin>>n>>m;
        queue<pair<int,int>> q;
        q.push(make_pair(n,0));
        int count = 0;
        if(seive[m]==0)
        {
            while(q.size()!=0)
            {
                int p = q.front().first;
                if(p==m)
                {
                    cout<<q.front().second<<endl;
                    break;
                }
                int d = p%10;
                int c = (p/10)%10;
                int b = (p/100)%10;
                int a = (p/1000);
                for(int i=0; i<=9; i++)
                {
                    int f = a*1000+b*100+c*10+i;
                    if(seive[f]==0 and mark[f]==0)
                    {
                        q.push(make_pair(f,q.front().second+1));
                        mark[f] = 1;
                    }
                }
                for(int i=0; i<=9; i++)
                {
                    int f = a*1000+b*100+i*10+d;
                    if(seive[f]==0 and mark[f]==0)
                    {
                        q.push(make_pair(f,q.front().second+1));
                        mark[f] = 1;
                    }
                }
                for(int i=0; i<=9; i++)
                {
                    int f = a*1000+i*100+c*10+d;
                    if(seive[f]==0 and mark[f]==0)
                    {
                        q.push(make_pair(f,q.front().second+1));
                        mark[f] = 1;
                    }
                }
                for(int i=1; i<=9; i++)
                {
                    int f = i*1000+b*100+c*10+d;
                    if(seive[f]==0 and mark[f]==0)
                    {
                        q.push(make_pair(f,q.front().second+1));
                        mark[f] = 1;
                    }
                }
                q.pop();
            }
        }
        else
        {
            cout<<"Impossible"<<endl;
        }
        while(q.size()!=0)
            q.pop();
    }
    return 0;
}
