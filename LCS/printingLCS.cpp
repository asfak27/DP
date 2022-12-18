#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[5000][5000];
string lcs(string s1,string s2)
{
    ll i,j;
    for(i=0; i<=s1.size(); i++)
    {
        for(j=0; j<=s2.size(); j++)
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
    string s="";
    i=s1.size();
    j=s2.size();
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            s+=s1[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i][j-1]>dp[i-1][j])
            {
                j--;
            }
            else{
                i--;
            }

        }
    }
    reverse(s.begin(),s.end());
    return s;
}
void solve()
{
    ll n,m,j,y,i,k,x,c,d,l,r;
    string s1,s2,s;
    cin>>s2>>s1;
    s=lcs(s1,s2);
    cout<<s<<endl;
}
int main()
{
    int T=1;
   // cin>>T;
    while(T--)solve();
    return 0;
}
