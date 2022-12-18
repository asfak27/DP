#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 5000
ll dp[mx+1][mx+1];
ll lcs(string s1,string s2,ll n,ll m)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    else if(s1[n-1]==s2[m-1])
    {
        return dp[n][m]=1+lcs(s1,s2,n-1,m-1);
    }
    else{
        return dp[n][m]=max(lcs(s1,s2,n,m-1),lcs(s1,s2,n-1,m));
    }
}
void solve()
{
    memset(dp,-1,sizeof(dp));
    ll n,m,j=0,y,i,k,x,c,d,l,r;
    string s1,s2;
    cin>>n>>m>>s1>>s2;
    ll len1=s1.size();
    ll len2=s2.size();
    ll res=lcs(s1,s2,len1,len2);
    cout<<res<<endl;
}
int main()
{
    int T;
    //cin>>T;
    while(T--)solve();
    return 0;
}
