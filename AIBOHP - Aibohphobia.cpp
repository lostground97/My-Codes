#include <bits/stdc++.h>
using namespace std;

int lcs(string str, string str1)
{
    int n = str.size();
    int mat[n+1][n+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 || j==0)
                mat[i][j] = 0;
            else
            {
                if(str[i-1]==str1[j-1])
                    mat[i][j] = mat[i-1][j-1] + 1;
                else
                    mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }
    return mat[n][n];
}

int solve(string str, int n)
{
    string str1;
    str1 = str;
    reverse(str1.begin(),str1.end());
    return n - lcs(str,str1);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        int n = str.size();
        int ans = solve(str,n);
        printf("%d\n",ans);
    }
    return 0;
}
