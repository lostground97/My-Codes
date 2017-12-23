#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll tree[4000008];
ll lazy[4000008];
ll arr[1000002];

void updateRange(ll node, ll start, ll end, ll l, ll r, ll val)
{
    if(lazy[node] != 0)
    { 
        tree[node] += (end - start + 1) * lazy[node];
        if(start != end)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > end or start > r or end < l)
        return;
    if(start >= l and end <= r)
    {
        tree[node] += (end - start + 1) * val;
        if(start != end)
        {
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    ll mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);
    updateRange(node*2 + 1, mid + 1, end, l, r, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll queryRange(ll node, ll start, ll end, ll l, ll r)
{
    if(start > end or start > r or end < l)
        return 0;
    if(lazy[node] != 0)
    {
        tree[node] += (end - start + 1) * lazy[node];
        if(start != end)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start >= l and end <= r)
        return tree[node];
    ll mid = (start + end) / 2;
    ll p1 = queryRange(node*2, start, mid, l, r);
    ll p2 = queryRange(node*2 + 1, mid + 1, end, l, r);
    return (p1 + p2);
}

int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        ll c;
        scanf("%lld",&c);
        memset(arr,0,sizeof(arr));
        memset(lazy,0,sizeof(lazy));
        memset(tree,0,sizeof(tree));
        while(c--)
        {
            ll ty, u, v;
            scanf("%lld%lld%lld",&ty,&u,&v);
            if(ty==0)
            {
                ll val;
                scanf("%lld",&val);
                updateRange(1,1,n,u,v,val);
            }
            if(ty==1)
            {
                ll ans = queryRange(1,1,n,u,v);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
