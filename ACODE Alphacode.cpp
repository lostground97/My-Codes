#include <bits/stdc++.h>
using namespace std;

string str;
long long int dp[5005];
int e;

long long int solve(int s = 0) {
	if (s > e) 
        return 1;
	if (dp[s]) 
        return dp[s];
	if (str[s] == '0') 
        return 0;

	if ((s+1 < e) and (str[s] == '1' or (str[s] == '2' and str[s+1] <= '6')))
	{
		if (str[s+1] == '0')
			return dp[s] = solve(s+2);
		else
			return dp[s] = solve(s+1) + solve(s+2);
	}
	else 
	    return dp[s] = solve(s+1);
}

int main() {
    while (1) {
        cin>>str;
        if (str[0] == '0') 
          break;
        e = str.size();
        memset(dp, 0, sizeof dp);
        printf("%lld\n", solve());
    }
    return 0;
}
