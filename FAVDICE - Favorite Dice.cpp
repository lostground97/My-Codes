#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        float e = 0;
        for(int i=1; i<=n; i++)
        {
            e = e + (float)n/(float)(n-(i-1));
        }
        printf("%0.2f\n",e);
    }
}
