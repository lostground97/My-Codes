#include <iostream>
using namespace std;

#define ll long long

int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        ll arr[n+1];
        int flag = 0;
        for(int i=0; i<n; i++)
            scanf("%lld",&arr[i]);
        for(int i=0; i<n-1; i++)
        {
            if(arr[i+1]>=arr[i])
            {
                arr[i+1] = arr[i+1] - arr[i];
                arr[i] = 0;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if(arr[n-1]!=0)
            flag = 1;
        if(flag==1)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
