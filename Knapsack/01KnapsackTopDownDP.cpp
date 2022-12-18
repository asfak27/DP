#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll knapSack(ll wt[], ll val[], ll n,ll W)
{
    ll i, w,j;
    ll dp[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)dp[i][j] = 0;

            else if (wt[i - 1] <= j)
                dp[i][j] = max(dp[i-1][j] , val[i-1]+dp[i-1][j-wt[i-1]]);

            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}
int main()
{
    vector<ll>v,v1;
    map<ll,ll>mp;
    ll n,m,j,i,k,len,z,p,x,y,h;
    cin>>n>>k;
    ll a[n+2],b[n+2];
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(i=0; i<n; i++)
    {
        cin>>b[i];
    }
    x=knapSack(a,b,n,k);
    cout<<x<<endl;
}

#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll       long long int
#define mod      1000000007
#define N        200005
#define yes      cout<<"YES"<<endl
#define no      cout<<"NO"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll dp[101][N];
ll a[N],b[N],k,n;
ll dfs(ll idx,ll val)
{
    if(val>k)return -2e9;

    if(idx==n)return 0;

    if(dp[idx][val]!=-1)return dp[idx][val];

    ll take=dfs(idx+1,val+a[idx])+b[idx];
    ll ntake=dfs(idx+1,val);

    return dp[idx][val]=max(take,ntake);
}
ll dfs(ll idx,ll a[],ll b[],ll n,ll target)
{
    if(idx>=n)return 0;

    if(dp[idx][target]!=-1)return dp[idx][target];
    ll ans=dfs(idx+1,a,b,n,target);
    if(target>=a[idx])
    {
        ans=max(ans,dfs(idx+1,a,b,n,target-a[idx])+b[idx]);
    }
    return dp[idx][target]=ans;
}
void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<vector<ll>>v;
    map<ll,ll>mp;
    set<ll>st;
    ll e,i,j,l,m,x,y,z,r,h;
    string s,t;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    memset(dp,-1,sizeof dp);
    ll ans=dfs(0,0);
    cout<<ans<<endl;
}
int main()
{
    fast;
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}
