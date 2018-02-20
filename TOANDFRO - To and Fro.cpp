#include <bits/stdc++.h>
using namespace std;

int main()
{
    while(1)
    {
        int n;
        cin>>n;
        if(n==0)
            break;
        string str;
        cin>>str;
        int c = str.size()/n;
        char mat[202][202];
        int count = 0;
        for(int i=1; i<=c; i++)
        {
            if(i%2==1)
            {
                for(int j=0; j<n; j++)
                {
                    mat[i][j+1] = str[count];
                    count++;
                }
            }
            if(i%2==0)
            {
                for(int j=n-1; j>=0; j--)
                {
                    mat[i][j+1] = str[count];
                    count++;
                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=c; j++)
            {
                cout<<mat[j][i];
            }
        }
        cout<<endl;
    }
}
