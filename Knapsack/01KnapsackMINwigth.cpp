#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9;
ll dp[1000][20010];
ll minwidth(ll a[],ll b[],ll n,ll k)
{
    ll i,j;
    for (i = 0; i < 1010; i++)
    {
        for (int j = 0; j < 20010; j++)
        {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 20010; j++)
        {
            dp[i+1][j] = dp[i][j];
            if (j>= a[i])
            {
                dp[i+1][j]=min(dp[i+1][j], b[i]+dp[i+1][j-a[i]]);
            }
        }
    }
    ll res = INF;
    for (i = k; i < 20010; i++)
    {
        res=min(res, dp[n][i]);
    }
    return res;
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
        cin>>a[i]>>b[i];
    }
    x=minwidth(b,a,n,k);
    cout<<x<<endl;
}
/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9+5;
const int N = 1e5+5;
ll dp[105][N];
ll minwidth(ll a[],ll b[],ll n,ll k)
{
    ll i,j;
    for(int i=1;i<N;i++)
    {
            dp[0][i] = INF ;
    }
    dp[0][0] = 0;
    for (i = 1; i<=n; i++)
    {
        for (j = 0; j <N; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (j>= b[i])
            {
                dp[i][j]=min(dp[i][j], a[i]+dp[i-1][j-b[i]]);
            }
        }
    }
    ll ans = 0;
    for (i = 0; i <N; i++)
    {
       if (dp[n][i] <= k)
        {
            ans = max(ans, i);
        }
    }
    return ans;
}
int main()
{
    vector<ll>v,v1;
    map<ll,ll>mp;
    ll n,m,j,i,k,len,z,p,x,y,h;
    cin>>n>>k;
    ll a[n+2],b[n+2];
    for(i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i];
    }
    x=minwidth(a,b,n,k);
    cout<<x<<endl;
}
*/
