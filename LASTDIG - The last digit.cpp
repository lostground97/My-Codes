#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll power(ll x, ll y, ll p)
{
    ll res = 1;
 
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res%p*x%p) % p;
        y = y/2;
        x = (x%p*x%p) % p;  
    }
    return res;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a, b;
        cin>>a>>b;
        ll ans = power(a,b,10);
        cout<<ans<<endl;
    }
}
