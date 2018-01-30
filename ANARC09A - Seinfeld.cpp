#include <bits/stdc++.h>
using namespace std;

int main()
{
    int c = 1;
    while(1)
    {
        string str;
        cin>>str;
        int ans = 0;
        if(str[0]=='-')
            break;
        int n = str.size();
        stack<char> s;
        for(int i=0; i<n; i++)
        {
            if(str[i]=='}')
            {
                if(s.size()==0)
                {
                    ans++;
                    s.push('{');
                }
                else
                {
                    s.pop();
                }
            }
            if(str[i]=='{')
            {
                s.push('{');
            }
        }
        ans = ans + (s.size())/2;
        cout<<c<<". "<<ans<<endl;
        c++;
    }
    return 0;
}
