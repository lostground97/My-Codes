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

vector<cpx> fft1(vector<ll> a)
{
    ll p = a.size();
    if(p==1)
    {
        vector<cpx> tmp;
        tmp.pb(cpx(1.0*a[0],0.0));
        return tmp;
    }
    ll h = p/2;
    vector<ll> xeven, xodd;
    for(ll i=0; i<h; i++)
    {
        xeven.pb(a[i<<1]);
        xodd.pb(a[i<<1^1]);
    }
    vector<cpx> yeven = fft1(xeven);
    vector<cpx> yodd = fft1(xodd);
    cpx w(1,0),wn(cos(2*pi/p),sin(2*pi/p));
    vector<cpx> ret(p);
    for(ll i=0; i<h; i++)
    {
        ret[i] = yeven[i] + w*yodd[i];
        ret[i+h] = yeven[i] - w*yodd[i];
        w = w*wn;
    }
    return ret;
}

vector<cpx> fft2(vector<cpx> a)
{
    ll p = a.size();
    if(p==1)
    {
        return a;
    }
    ll h = p/2;
    vector<cpx> xeven, xodd;
    for(ll i=0; i<h; i++)
    {
        xeven.pb(a[i<<1]);
        xodd.pb(a[i<<1^1]);
    }
    vector<cpx> yeven = fft2(xeven);
    vector<cpx> yodd = fft2(xodd);
    cpx w(1,0),wn(cos(2*pi/p),sin(-2*pi/p));
    vector<cpx> ret(p);
    for(ll i=0; i<h; i++)
    {
        ret[i] = yeven[i] + w*yodd[i];
        ret[i+h] = yeven[i] - w*yodd[i];
        w = w*wn;
    }
    return ret;
}

vector<cpx> multiply(vector<cpx> a, vector<cpx> b)
{
    vector<cpx> p;
    ll n = a.size();
    ll m = b.size();
    ll mn = min(n,m);
    ll mx = max(n,m);
    for(ll i=0; i<mn; i++)
        p.pb(a[i]*b[i]);
    for(; mn<mx; mn++)
        p.pb(cpx(0.0,0.0));
    return p;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll test;
	cin>>test;
	while(test--)
	{
    	vector<ll> a, b;
    	ll n, m;
    	cin>>n;
    	n++;
    	m = n;
    	for(ll i=n; i--;)
    	{
    	    ll x;
    	    cin>>x;
    	    a.pb(x);
    	}
    	reverse(all(a));
    	ll t = 1;
    	while(t<=n)
    	    t<<=1;
    	for(ll i=n; i<t; i++)
    	    a.pb(0);
    	t<<=1;
    	for(ll i=t>>1; i<t; i++) 
    	    a.push_back(0);
    	for(ll i=m; i--;)
    	{
    	    ll x;
    	    cin>>x;
    	    b.pb(x);
    	}
    	reverse(all(b));
    	t = 1;
    	while(t<=m)
    	    t<<=1;
    	for(ll i=m; i<t; i++)
    	    b.pb(0);
        t<<=1;
    	for(ll i=t>>1; i<t; i++) 
    	    b.push_back(0);	   
    	vector<cpx> ay = fft1(a);
    	vector<cpx> by = fft1(b);
    	vector<cpx> cy = multiply(ay,by);
    	cy = fft2(cy);
    	//cout<<n<<" "<<m<<endl;
    	for(ll i=n+m-2;i>=0;i--)
    	{
    		cout<<(ll)(round(real(cy[i]))/t)<<" ";
    	}
    	cout<<endl;
    	a.clear();
    	b.clear();
    	ay.clear();
    	by.clear();
    	cy.clear();
	}
}
