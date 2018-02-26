#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long int a, b, s,sum = 0;
		cin>>a>>b>>s;
		long long int r, A, n;
		if(a==b)
		{
		    r = 1;
		    n = s/a;
		    cout<<n<<endl;
		    for(int i=1; i<=n; i++)
		        cout<<a<<" ";
		}
		else
		{
		    r = 2;
		    while(1)
		    {
		        if((r*r*r*r*r*b-a)==(s*r*r*(r-1)))
		        {
		            break;
		        }
		        r++;
		    }
		A = a/(r*r);
		vector<long long int> vec;
		long long int yy = A;
		while(sum!=s)
		{
		    vec.push_back(yy);
		    sum = sum + yy;
		    yy = yy*r;
		}
		cout<<vec.size()<<endl;
		for(int i=0; i<vec.size(); i++)
		    cout<<vec[i]<<" ";
	    cout<<endl;
		}
	}
	return 0;
}
