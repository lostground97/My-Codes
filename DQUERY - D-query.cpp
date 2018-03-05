#include <bits/stdc++.h>
using namespace std;

int block;

struct node{
    int l;
    int r;
    int idx;
};

bool compare(struct node x, struct node y) 
{
	if(x.l/block!=y.l/block) 
	{
		return x.l/block<y.l/block;
	}
	return x.r<y.r;
}

int main()
{
    int n,m;
    scanf("%d",&n);
    block = sqrt(n);
    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    scanf("%d",&m);
    struct node qr[m];
    int ans[m];
    for(int i=0; i<m; i++)
    {
        int x, y;
        scanf("%d%d",&x,&y);
        qr[i].l = x-1;
        qr[i].r = y-1;
        qr[i].idx = i;
    }
    sort(qr,qr+m,compare);
    int count[1000005] = {0};
    int answer = 0;
    int cl = 0, cr = 0;
    for(int i=0; i<m; i++)
    {
        int cll = qr[i].l, crr = qr[i].r, ii = qr[i].idx;
        while(cl<cll)
        {
            count[arr[cl]]--;
            if(count[arr[cl]]==0)
                answer--;
            cl++;
        }
        while(cl>cll)
        {
            count[arr[cl-1]]++;
            if(count[arr[cl-1]]==1)
                answer++;
            cl--;
        }
        while(cr<=crr)
        {
            count[arr[cr]]++;
            if(count[arr[cr]]==1)
                answer++;
            cr++;
        }
        while(cr>crr+1)
        {
            count[arr[cr-1]]--;
            if(count[arr[cr-1]]==0)
                answer--;
        }
        ans[ii] = answer;
    }
    for(int i=0; i<m; i++)
        printf("%d\n",ans[i]);
    return 0;
}
