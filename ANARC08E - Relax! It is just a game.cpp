#include <bits/stdc++.h>
using namespace std;

long long int fact(int n)
{
    int ans = 1;
    for(int i=1; i<=n; i++)
        ans = ans*i;
    return ans;
}

int main()
{
    while(1)
    {
        int m, n;
        cin>>m>>n;
        if(m==-1 or n==-1)
            break;
        long long int ans = fact(m+n)/(fact(n)*fact(m));
        if(ans==(m+n))
        {
            cout<<m<<"+"<<n<<"="<<(m+n);
        }
        else
        {
            cout<<m<<"+"<<n<<"!="<<(m+n);
        }
        cout<<endl;
    }
    return 0;
}
