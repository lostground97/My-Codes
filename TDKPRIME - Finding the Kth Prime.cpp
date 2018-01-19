#include <bits/stdc++.h>
using namespace std;

#define N 87000008
int factor[N+1];
vector<int> prime;

void sieve()
{
    
    for (int i=2; i<=N; ++i) 
    {
        if (factor[i] == 0) {
            factor[i] = i;
            prime.push_back (i);
        }
        for (int j=0; j<(int)prime.size() && prime[j]<=factor[i] && i*prime[j]<=N; ++j)
            factor[i * prime[j]] = prime[j];
    }
}

int main()
{
    prime.push_back(0);
    sieve();
    long long int q, k;
    cin>>q;
    for(int i=1; i<=q; i++)
    {
        cin>>k;
        cout<<prime[k]<<endl;
    }
    return 0;
}
