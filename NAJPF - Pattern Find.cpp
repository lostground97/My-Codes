#include <bits/stdc++.h>
using namespace std;

int main()
{
     int t;
     cin>>t;
     while(t--)
     {
          string s,p;
          cin>>s>>p;
          int n = p.size();
          int lps[n];
          lps[0] = 0;
          vector<int> vec;
          int len = 0;
          int i = 1;
          while(i<n)
          {
               if(p[i]==p[len])
               {
                    len++;
                    lps[i] = len;
                    i++;
               }
               else
               {
                    if(len!=0)
                    {
                         len = lps[len-1];
                    }
                    else
                    {
                         lps[i] = 0;
                         i++;
                    }
               }
          }
          i = 0;
          int j = 0;
          int m = s.size();
          while(i<m)
          {
               if(s[i]==p[j])
               {
                    i++;
                    j++;
               }
               if(j==n)
               {
                    vec.push_back(i-j+1);
                    j = lps[j-1];
               }
               if(s[i]!=p[j] and i<m)
               {
                    if(j!=0)
                    {
                         j = lps[j-1];
                    }
                    else
                    {
                         i++;
                    }
               }
          }
          if(vec.size()!=0)
               cout<<vec.size()<<endl;
          else
               cout<<"Not Found"<<endl;
          for(int i=0; i<vec.size(); i++)
          { 
               cout<<vec[i]<<" ";
               if(i+1==vec.size())
                    cout<<endl;
          }
          cout<<endl;
     }
}
