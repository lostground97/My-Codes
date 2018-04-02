#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    long long int y = log2(n);
    long long int z = pow(2,y);
    if(n==z)
    {
        printf("TAK\n");
        return 0;
    }
    printf("NIE\n");
    return 0;
}
