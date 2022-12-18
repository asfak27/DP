#include<bits/stdc++.h>
using namespace std;
#define ll int
#define  mod       1000000007
ll coinchang(ll coin[],ll n,ll sum)
{
    ll dp[n + 1][sum + 1],i,j;

    for (i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (i = 1; i <= sum; i++)
        dp[0][i] = 0;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= sum; j++)
        {
            if (j >= coin[i - 1])
            {
                dp[i][j] = (dp[i - 1][j]+dp[i][j - coin[i - 1]])%mod;
            }
            else dp[i][j] = dp[i - 1][j];
        }
    }
    /*for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return dp[n][sum];
}
void solve()
{
    vector<ll>v,v1;
    map<ll,ll>mp;
    ll n,m,j,i,k,len,z,p,x,y;
    cin>>n>>k;
    ll a[n+2];
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    x=coinchang(a,n,k);
    cout<<x<<endl;
}
int main()
{
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}

