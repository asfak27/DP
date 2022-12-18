#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[7000][7000];
ll lcs(string s1,string s2)
{
    ll i,j;
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
    return len1+len2-dp[s1.length()][s2.length()];
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
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}

