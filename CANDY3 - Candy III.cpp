#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n, p,sum = 0;
        cin>>n;
        for(long long int i=1; i<=n; i++)
        {
            cin>>p;
            sum = (sum%n + p%n)%n;
        }
        if(sum%n==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
