#include <bits/stdc++.h>
using namespace std;
#define mx 1007

int dp[mx][mx];

// Function to find the length of Longest Repeated Subsequence
// of substring X[0..m-1] and X[0..n-1]
int LRSLength(string X, int m, int n)
{
	// return if we have reached the end of either string
	if (m == 0 || n == 0)
		return 0;
    if(dp[m][n]!=-1) return dp[m][n];

	// if characters at index m and n matches and index is different
	if (X[m - 1] == X[n - 1] && m != n)
		return dp[m][n]=LRSLength(X, m - 1, n - 1) + 1;

	// else if characters at index m and n don't match
	return dp[m][n]= max (LRSLength(X, m, n - 1), LRSLength(X, m - 1, n));
}

int main()
{
    memset(dp,-1,sizeof dp);
	string X = "ATACTCGGA";
	int m = X.length();
	int ans = LRSLength(X, m, m);

	cout << "Length of Longest Repeating Subsequence is "<<ans<<endl;

	return 0;
}
