//Some random shit goes here. I don't know why
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector< ll >
#define pair < ll,ll > pi
#define vpair vector < pi >
#define pb push_back
#define mp make_pair
#define in insert
#define mod 1000000007
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define zero(x) memset(x, 0, sizeof(x))
#define dpset(x) memset(x, -1, sizeof(x))

struct root{
	int open;
	int close;
};

root tree[4000005];

ll modexp(ll x, ll y)
{
	ll ans = 1;
	x = x%mod;
	while(y>0)
	{
		if(y%2==1)
			ans = (ans%mod*x%mod)%mod;
		y = y/2;
		x = (x%mod*x%mod)%mod;
	}
	return ans;
}

void build(ll node, char* str, ll s, ll e)
{
	if(s>e)
		return;
	if(s==e)
	{
		if(str[s-1]=='(')
		{
			tree[node].open = 1;
			tree[node].close = 1;
		}
		else
		{
			tree[node].open = -1;
			tree[node].close = -1;
		}
		return;
	}
	ll mid = (s+e)/2;
	ll left = 2*node, right = left + 1;
	build(left,str,s,mid);
	build(right,str,mid+1,e);

	tree[node].open = tree[left].open + tree[right].open;
	tree[node].close = min(tree[left].close, tree[left].open + tree[right].close);
	return;
}

void update(ll node, ll idx, ll s, ll e)
{
	if(s==e and s==idx)
	{
		tree[node].open = -tree[node].open;
		tree[node].close = tree[node].open;
		return;
	}
	ll mid = (s+e)/2;
	if(idx>mid)
		update(2*node+1,idx,mid+1,e);
	else
		update(2*node,idx,s,mid);
	
	ll left = 2*node, right = left + 1;
	tree[node].open = tree[left].open + tree[right].open;
	tree[node].close = min(tree[left].close, tree[left].open + tree[right].close);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 10;
	int c = 1;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		char str[n];
		scanf("%s", str);
		build(1,str,1,n);
		int q;
		scanf("%d",&q);
		printf("Test %d:\n",c);
		c++;
		while(q--)
		{
			int m;
			scanf("%d",&m);
			if(m==0)
			{
				if(!tree[1].open && !tree[1].close)
				{
					printf("YES\n");
				}
				else
				{
					printf("NO\n");
				}
			}
			else
			{
				update(1,m,1,n);
			}
		}
	}
}
