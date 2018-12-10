#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector< ll >
#define pair < ll,ll > pi
#define vpair vector < pi >
#define pb push_back
#define mp1 make_pair
#define in insert
#define mod 1000000007
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define zero(x) memset(x, 0, sizeof(x))
#define dpset(x) memset(x, -1, sizeof(x))


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

map<string, bool> mp;

bool fun(string s)
{
	if(s.size()==0)
	{
		return true;
	}
	if(mp.find(s)!=mp.end())
		return mp[s];
	bool a = false;
	int count = 0;
	for(int i=0; i<s.size(); i++)
	{
		int j;
		for(j=i+1; j<s.size(); j++)
		{
			if(s[i]!=s[j])
				break;
		}
		if(i+2<=j)
		{
			string ss = s.substr(0,i) + s.substr(j);
			a = a + fun(ss);
			if(a==true)
			{
				return a;
				mp[s] = true;
			}
			i = j - 1;
		}
	}
	mp[s] = a;
	return a;
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
		string s;
		cin>>s;
		if(fun(s)==true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}