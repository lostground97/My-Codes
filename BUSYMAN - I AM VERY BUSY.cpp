#include <bits/stdc++.h>
using namespace std;

struct act
{
	int f,s;
}arr[100000];

bool comp(struct act a,struct act b)
{
	if (a.s == b.s)
		return a.f<b.f;
	return a.s<b.s;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i].f>>arr[i].s;
        }
        sort(arr,arr+n,comp);
        int count = 0, end=-1;
        for(int i=0; i<n; i++)
        {
            if(arr[i].f>=end)
            {
                count++;
                end = arr[i].s;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
