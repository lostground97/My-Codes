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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vi v;
	for(int i=0; i<n; i++)
	{
	    ll x;
	    cin>>x;
	    v.pb(x);
	}
	sort(all(v));
	vi d;
	for(int i=1; i<n; i++)
	{
	    ll p = v[i] - v[i-1];
	    d.pb(p);
	}
	ll p = 0;
	for(int i=0; i<d.size(); i++)
	{
	    p = __gcd(p,d[i]);
	}
	ll x = 1 + (v[v.size()-1]-v[0])/p;
	x = x - n;
	cout<<x<<endl;
}
