#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int ans[t];
    for(int x=0; x<t; x++)
    {
        int a,n;
        cin>>a>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int toll = 0, count = 0;
        for(int i=n-1; i>=0; i--)
        {
            toll = toll+arr[i];
            if(toll>=a)
            {
                count++;
                break;
            }
            count++;
        }
        if(toll<a)
            count = -1;
        ans[x] = count;
    }
    for(int x=0; x<t; x++)
    {
        printf("Scenario #%d:\n",x+1);
        if(ans[x]!=-1)
            cout<<ans[x]<<endl;
        else
            cout<<"impossible\n";
    }
    return 0;
}
