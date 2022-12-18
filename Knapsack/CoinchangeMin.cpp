#include<bits/stdc++.h>
using namespace std;
#define ll int
#define  no               cout<<"No"<<endl
#define  yes              cout<<"Yes"<<endl
#define  N    1000005
#define  mod       10000007
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll coinchange(ll a[],ll n,ll k)
{
    ll dp[n+2][k+2],i,j;//vector<vector<ll>>dp(n+1,vector<ll>(k+1));
    for(i=1;i<=k;i++)
    {
        if(i%a[0]==0)dp[0][i]=i/a[0];
        else dp[0][i]=mod;
    }
    for(i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(a[i]>j)dp[i][j]=dp[i-1][j];
            else
            {
                dp[i][j]=min(dp[i-1][j],dp[i][j-a[i]]+1);
            }
        }

    }
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<=k;j++)
        {
           cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return dp[n-1][k];
}
void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<ll>v;
    map<ll,ll>mp;
    map<ll,ll>mp1;
    ll e,i,j,l,m,x,y,z,r,k,n;
    cin>>n>>k;
    ll a[n+1];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    x=coinchange(a,n,k);
    if(x!=mod)cout<<x<<endl;
    else cout<<-1<<endl;

}
int main()
{
    fast;
    int T=1;
   // cin>>T;
    while(T--)solve();
    return 0;
}
