#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	long int t;
	scanf("%ld",&t);
	while(t--)
	{
		char str[1000005];
		scanf("%s",str);
		int len = strlen(str);
		int flag = -1,carry=0;
		float x = (float)len/2.0;
		int mid = ceil(x)-1;
		int i;
		if(len%2==0)
		{
    		for(i=mid; i>=0; i--)
    		{
    			if(str[i]>str[len-1-i])
    				if(flag==-1)
    					flag = 1;
    			if(str[i]<str[len-1-i])
    				if(flag==-1)
    					flag=0;
    			str[len-1-i] = str[i];
    		}
		}
		else
		{
		    for(i=mid-1; i>=0; i--)
    		{
    			if(str[i]>str[len-1-i])
    				if(flag==-1)
    					flag = 1;
    			if(str[i]<str[len-1-i])
    				if(flag==-1)
    					flag=0;
    			str[len-1-i] = str[i];
    		}
		}
		if(flag==0)
		{
			if(len%2==0)
			{
				if(str[mid]=='9')
				{
					str[mid] = '0';
					str[mid+1] = '0';
					carry=1;
				}
				else
				{
					str[mid] = str[mid] + 1;
					str[mid+1] = str[mid+1] + 1;
					carry=0;
				}
			}
			else
			{
				if(str[mid]=='9')
				{
					str[mid] = '0';
					carry = 1;
				}
				else
				{
					str[mid] = str[mid] + 1;
					carry = 0;
				}
			}
			int i = mid-1;
			while(carry==1)
			{
				if(str[i]=='9')
				{
					str[i] = '0';
					str[len-1-i] = '0';
				}
				else
				{
					str[i] = str[i] + 1;
					str[len-1-i] = str[i];
					carry=0;
				}
				i--;
			}
		}
		if(flag==-1)
		{
		    i=mid;
		    if(len%2==0)
			{
				if(str[i+1]=='9')
				{
					str[i+1] = '0';
					str[i] = '0';
					carry=1;
				}
				else
				{
					str[i+1] = str[i+1] + 1;
					str[i] = str[i] + 1;
					carry=0;
				}
			}
			else
			{
				if(str[i]=='9')
				{
					str[i] = '0';
					carry = 1;
				}
				else
				{
					str[i] = str[i] + 1;
					carry = 0;
				}
			}
			i = mid-1;
			while(carry==1 && i>=0)
			{
				if(str[i]=='9')
				{
					str[i] = '0';
					str[len-1-i] = '0';
				}
				else
				{
					str[i] = str[i] + 1;
					str[len-1-i] = str[i];
					carry=0;
				}
				i--;
			}
		}
		if(carry==1)
        {
            printf("1");
            for(i=1; i<len; i++)
            {
                printf("0");
            }
            printf("1\n");
        }
        else
        {
            for(i=0; i<len; i++)
            {
                    printf("%c",str[i]);
            }
            printf("\n");
        }
	}
	return 0;
}
