#include<bits/stdc++.h>
using namespace std;
#define ll int
ll dp[7001][7001];
ll lcs(string s1,string s2)
{
    ll i,j,x;
    ll len1=s1.size();
    ll len2=s2.size();
    for(i=0; i<=s1.length(); i++)
    {
        for(j=0; j<=s2.length(); j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[len1][len2];
}
void solve()
{
    ll n;
    string s1,s2="";
    cin>>n>>s1;
    s2+=s1;
    reverse(s1.begin(),s1.end());
    ll x=lcs(s1,s2);
    cout<<n-x<<'\n';
}
int main()
{
    int T=1;
   // cin>>T;
    while(T--)solve();
    return 0;
}


