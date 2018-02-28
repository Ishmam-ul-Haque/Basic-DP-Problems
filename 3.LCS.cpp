#include <bits/stdc++.h>
using namespace std;

#define mx 1007

int dp[mx][mx];

// sequences X[0..m-1] and Y[0..n-1]
int LCSLength(string X, string Y, int m, int n)
{
    // return if we have reached the end of either sequence
    if (m == 0 || n == 0)
        return 0;

    // if last character of X and Y matches
    if (X[m - 1] == Y[n - 1])
        return dp[m][n] = LCSLength(X, Y, m - 1, n - 1) + 1;

    // else if last character of X and Y don't match
    return dp[m][n] = max(LCSLength(X, Y, m, n - 1), LCSLength(X, Y, m - 1, n));
}

int main()
{
    memset(dp,-1,sizeof dp);
    string X = "ABCBDAB", Y = "BDCABA";
    int ans= LCSLength(X, Y, X.length(), Y.length());

    cout << "The length of LCS is " << ans <<endl;

    return 0;
}
