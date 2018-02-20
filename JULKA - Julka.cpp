#include <boost/multiprecision/cpp_int.hpp>
#include <bits/stdc++.h>
namespace mp = boost::multiprecision;
using namespace std;

int main()
{
    int t = 10;
    while(t--)
    {
        mp::cpp_int u, v, x, y;
        cin>>u>>v;
        u = u - v;
        u = u/2;
        x = u;
        y = u + v;
        cout<<y<<endl;
        cout<<x<<endl;
    }
}
