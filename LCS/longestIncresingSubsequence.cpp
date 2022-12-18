#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define  no               cout<<"No"<<endl
#define  yes              cout<<"Yes"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int const N=1e7+3;
void solve()
{
    vector<ll>v,v1;
    map<ll,ll>mp;
    map<ll,ll>mp2;
    ll n,m,j,i,x,y,z,k,l,r,b;
    cin>>n;
    ll a[n+1];
    ll dp[n+1];
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        dp[i]=0;
    }
    ll mx=0;
    for(i=0; i<n; i++)
    {
        mx=0;
        for(j=0; j<i; j++)
        {
            x=abs(a[i]);
            y=abs(a[j]);
            if(y<x)
            {
                mx=max(mx,dp[j]);
            }
        }
        dp[i]=mx+1;
    }
    ll ans=0;
    for(i=0; i<n; i++)
    {
        ans=max(dp[i],ans);
    }
    cout<<ans<<endl;


}
int main()
{
    fast;
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
#define ll int
#define  no               cout<<"No"<<endl
#define  yes              cout<<"Yes"<<endl
int main()
{
    ll n,m,j,y,i,k,x,z,l,r,temp,T=1,c=1;
   // cin>>T;
    while(T--)
    {
        cin>>n;
        ll a[n+2],dp[n+2];
        for(i=1;i<=n;i++)
        {
            dp[i]=1e9;
        }
        dp[0]=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {
            x=upper_bound(dp,dp+n+1,a[i])-dp;
            if(a[i]>dp[x-1]&&a[i]<dp[x])
            {
                dp[x]=a[i];
            }
        }
        ll ans=0;
        for(i=n;i>=0;i--)
        {
            if(dp[i]!=1e9)
            {
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
*/
int dfs(int n,int a[],int curr,int prev,vector<vector<int>>&dp)
{
    if(curr==n)return 0;

    if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];

    int take=0;
    if(prev==-1 || a[curr]>a[prev])
    {
        take=1+dfs(n,a,curr+1,curr,dp);
    }
    int ntake=0+dfs(n,a,curr+1,prev,dp);

    return dp[curr][prev+1]=max(take,ntake);
}


int longestSubsequence(int n, int a[])
{
    // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

    vector<int>v;
    v.push_back(a[0]);
    for(int i=1; i<n; i++)
    {
        if(v.back()<a[i])
        {
            v.push_back(a[i]);
        }
        else
        {
            int idx=lower_bound(v.begin(),v.end(),a[i])-v.begin();

            v[idx]=a[i];

        }
    }
    return v.size();
}
