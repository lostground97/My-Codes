#include <bits/stdc++.h>
using namespace std;

#define e 2.71828

int main()
{
    while(1)
    {
        float c;
        cin>>c;
        if(c==0.00)
            break;
        float x = 0.00;
        int i = 2;
        while(x<=c)
        {
            x = x + float(1)/(float)i;
            i++;
        }
        cout<<i-2<<" card(s)"<<endl;
    }
    return 0;
}
