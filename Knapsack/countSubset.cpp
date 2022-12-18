#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[10001][10001];
ll isSubsetSum(ll a[],ll n,ll sum)
{
    ll dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= sum; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (a[i - 1]<=j)
            {
                dp[i][j] = dp[i - 1][j]+dp[i - 1][j - a[i - 1]];
            }
            else dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
void solve()
{
    vector<ll>v,v1;
    map<ll,ll>mp;
    ll n,m,j,i,k,len,z,p,x,y;
    cin>>n>>k;
    ll a[n+2],b[n+2];
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    x=isSubsetSum(a,n,k);
    cout<<x<<endl;
}
int main()
{
    int T=1;
   // cin>>T;
    while(T--)solve();
    return 0;
}

