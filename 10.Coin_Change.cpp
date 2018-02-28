#include<bits/stdc++.h>
using namespace std;

#define mx 1007

int ar[]= {1,5,10,25,50};
int table[mx][6];

int coinChange(int ar[],int sum,int coin)
{
    if(sum==0) return 1;
    if(sum <0) return 0;
    if(sum>0 && coin<=0) return 0;
    if(table[sum][coin]!=-1) return table[sum][coin];
    return table[sum][coin]=coinChange(ar,sum,coin-1)+coinChange(ar,sum-ar[coin-1],coin);
}

int main()
{
    memset(table,-1,sizeof table);
    int total;
    cin>>total;
    int ans=coinChange(ar,total,5);
    cout<<"There are "<<ans<<" way(s) to produce "<<total<<" cents change."<<endl;
}
