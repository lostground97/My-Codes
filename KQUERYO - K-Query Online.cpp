#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> tree[150005];
ll arr[30005];

void build(ll node, ll s, ll e)
{
    if(s>e)
        return;
    if(s==e)
    {
        tree[node].push_back(arr[s]);
        return;
    }
    ll mid = s + (e-s)/2;
    ll left = 2*node;
    ll right = 2*node+1;
    build(2*node,s,mid);
    build(2*node+1,mid+1,e);
    merge(tree[left].begin(), tree[left].end(), tree[right].begin(), tree[right].end(), back_inserter(tree[node]));
    return;
}

ll query(ll node, ll s, ll e, ll x, ll y, ll k)
{
    if(s>y || e<x) 
        return 0 ;
    if(s>=x && e<=y)
    {
        return  tree[node].end() - upper_bound(tree[node].begin(),tree[node].end(),k) ;
    }
    ll mid = s + (e-s)/2;
    return query(2*node,s,mid,x,y,k) + query(2*node+1,mid+1,e,x,y,k);
}

int main()
{
    ll n;
    scanf("%lld",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&arr[i]);
    }
    build(1,1,n);
    ll q;
    scanf("%lld",&q);
    ll ans = 0;
    while(q--)
    {
        ll l, r, k;
        scanf("%lld%lld%lld",&l,&r,&k);
        l = l^ans;
        r = r^ans;
        k = k^ans;
        ans = query(1,1,n,l,r,k);
        printf("%lld\n",ans);
    }
    return 0;
}
