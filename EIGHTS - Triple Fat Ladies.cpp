#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        long long int ans;
        if(n==1)
            ans = 192;
        else
            ans = 192 + (n-1)*250;
        cout<<ans<<endl;
    }
}
