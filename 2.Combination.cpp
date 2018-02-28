#include<bits/stdc++.h>
using namespace std;

#define mx 1007

int dp[mx][mx];

int nCr(int n,int r)
{
  if (n==r || r==0)
    return dp[n][r]=1;
  if(dp[n][r]!=-1) return dp[n][r];
  return  dp[n][r]=nCr(n-1, r-1) + nCr(n-1, r);
}

int main()
{
    int a,b,ans;
    memset(dp,-1,sizeof dp);
    cin>>a>>b;
    ans=nCr(a,b);
    cout<<ans<<endl;
    return 0;
}
