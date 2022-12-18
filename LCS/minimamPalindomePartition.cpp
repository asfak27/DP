#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isPalindrome(string s,ll l,ll h)
{
	while(l<h)
	{
		if(s[l++]!=s[h--])
		{
			return false;
		}
	}
	return true;
}
ll solve(string s,ll i,ll j)
{
    ll k,x;
    if(i>=j)return 0;
    if(isPalindrome(s,i,j))return 0;
    ll mn=1e9;
    for(k=i;k<=j-1;k++)
    {
        x=solve(s,i,k)+solve(s,k+1,j)+1;
        mn=min(mn,x);
    }
    return mn;
}
void solve()
{
    vector<ll>v;
    map<ll,ll>mp;
    map<ll,ll>mp2;
    ll n,j,y,i,k,x,d,l,r;
    string s;
    cin>>s;
    x=solve(s,0,s.size()-1);
    cout<<x+1<<endl;
}
int main()
{
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll int
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll static dp[1001][1001];
bool isPalindrome(string s,ll l,ll h)
{
    while(l<h)
    {
        if(s[l++]!=s[h--])
        {
            return false;
        }
    }
    return true;
}
ll solve(string s,ll i,ll j)
{
    ll k,x,left,right;
    if(i>=j)return 0;
    if(isPalindrome(s,i,j))return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    ll mn=1e9;
    for(k=i; k<=j-1; k++)
    {
        if(dp[i][k]!=-1)
        {
            left=dp[i][k];
        }
        else
        {
            left=solve(s,i,k);
            dp[i][k]=left;
        }
        if(dp[k+1][j]!=-1)
        {
            right=dp[k+1][j];
        }
        else
        {
            right=solve(s,k+1,j);
            dp[k+1][j]=right;
        }
        x=left+right+1;
        mn=min(mn,x);
    }
    return dp[i][j]=mn;
}
int main()
{
    fast
    int T=1,c=0;
    cin>>T;
    while(T--)
    {
        vector<ll>v;
        map<ll,ll>mp;
        map<ll,ll>mp2;
        ll n,j,y,i,k,x,d,l,r;
        string s;
        cin>>s;
        c++;
        memset(dp,-1,sizeof(dp));
        x=solve(s,0,s.size()-1);
        cout<<"Case "<<c<<": "<<x+1<<endl;
    }
    return 0;
}

