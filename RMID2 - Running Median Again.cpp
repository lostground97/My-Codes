#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		ll m = INT_MAX;
		ll n;
		priority_queue <ll> s2;
		priority_queue < int, vector <int>, greater <int> > s1;
		while(1)
		{
			cin>>n;
			if(n==0)
			{
				m = INT_MAX;
				cout<<endl;
				break;
			}
			if(n==-1)
			{
				cout<<s2.top()<<endl;
				s2.pop();
				if(s2.size()<s1.size())
				{
					ll p = s1.top();
					s1.pop();
					s2.push(p);
				}
				//cout<<s1.size()<<" "<<s2.size()<<endl;
				continue;
			}
			if(s2.size()==s1.size() and s1.size()==0)
			{
				s2.push(n);
			}
			else
			{
				ll a = s2.top();
				if(n>=a)
				{
					s1.push(n);
				}
				else
				{
					s2.push(n);
				}
			}
			if(s2.size()<s1.size())
			{
				ll p = s1.top();
				s1.pop();
				s2.push(p);
			}
			else
			{
				if(s2.size()>s1.size()+1)
				{
					ll p = s2.top();
					s2.pop();
					s1.push(p);
				}
			}
		}
	}
}
