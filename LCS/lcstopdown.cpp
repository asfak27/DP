/*#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 10000
ll dp[mx+1][mx+1];
ll lcs(string s1,string s2,ll n,ll m)
{
   ll i,j;
   for(i=0;i<n+1;i++)
   {
       for(j=0;j<m+1;j++)
       {
           if(i==0||j==0)dp[i][j]=0;
       }
   }
   for(i=1;i<n+1;i++)
   {
       for(j=1;j<m+1;j++)
       {
           if(s1[i-1]==s2[j-1])
           {
               dp[i][j]=1+dp[i-1][j-1];
           }
           else{
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           }
       }
   }
}
void solve()
{
    ll n,m,j=0,y,i,k,x,c,d,l,r,mod=1e9+7;
    string s1,s2;
    cin>>s1>>s2;
    ll len1=s1.size();
    ll len2=s2.size();
    lcs(s1,s2,len1,len2);
    x=dp[len1][len2];
    for(i=0;i<len1+1;i++)
    {
        for(j=0;j<len2+1;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<dp[len1][len2]<<endl;
}
int main()
{
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[7000][7000];
ll lcs(string s1,string s2)
{
    ll i,j;
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
    return dp[s1.length()][s2.length()];
}
void solve()
{
    ll n,m,j=0,y,i,k,x,c,d,l,r,mod=1e9+7;
    string s1,s2;
    cin>>s2>>s1;
    x=lcs(s1,s2);
    cout<<x<<endl;
}
int main()
{
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}


