#include <bits/stdc++.h>
using namespace std;

int lps[100000];
vector<int> v1;

void ckmp(string &s1, string &x)
{
  int M = s1.size();
  int n = x.size();
  int i = 0;
  int j = 0;
  for(i=0; i<n; i++)
  {
       while(s1[j]!=x[i] and j>0)
          j = lps[j-1];
       if(s1[j]==x[i])
       {
            j++;
       }
       if(j==M)
       {
            v1.push_back(i-j+1);
            j = lps[j-1];
       }
  }
}

void clps(string &s1)
{
  int i = 0;
  int j = 0;
  int n = s1.size();
  lps[0] = 0;
  for(i=1; i<n; i++)
  {
     while(j>0 and s1[j]!=s1[i])
     {
          j = lps[j-1];
     }
     if(s1[i]==s1[j])
     {
          j++;
     }
     lps[i] = j;
  }
}

int main()
{
  int t;
  scanf("%d",&t);
  while(1)
  {
    string s1,s2;
    cin>>s1>>s2;
    clps(s1);
    ckmp(s1,s2);
    for(int i=0; i<v1.size(); i++)
      cout<<v1[i]<<endl;
    v1.clear();
    if(scanf("%d",&t)==1)
    {
         cout<<endl;
    }
    else
    {
         break;
    }
  }
}
