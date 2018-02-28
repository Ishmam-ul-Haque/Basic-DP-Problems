#include<bits/stdc++.h>
using namespace std;

int minimum(int x, int y, int z)
{
   return min(min(x, y), z);
}

#define mx 1007

int dp[mx][mx];

int editDist(string str1 , string str2 , int m ,int n)
{
    // If first string is empty, the only option is to
    // insert all characters of second string into first
    if (m == 0) return dp[m][n] = n;

    // If second string is empty, the only option is to
    // remove all characters of first string
    if (n == 0) return dp[m][n] = m;

    // If last characters of two strings are same, nothing
    // much to do. Ignore last characters and get count for
    // remaining strings.
    if (str1[m-1] == str2[n-1])
        return dp[m][n] = editDist(str1, str2, m-1, n-1);

    // If last characters are not same, consider all three
    // operations on last character of first string, recursively
    // compute minimum cost for all three operations and take
    // minimum of three values.
    return dp[m][n] = 1 + minimum( editDist(str1,  str2, m, n-1),    // Insert
                     editDist(str1,  str2, m-1, n),   // Remove
                     editDist(str1,  str2, m-1, n-1) // Replace
                   );
}

int main()
{
    string str1 = "sunday";
    string str2 = "saturday";

    int ans = editDist( str1 , str2 , str1.length(), str2.length());

    cout << ans <<endl ;

    return 0;
}
