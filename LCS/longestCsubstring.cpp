#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[7000][7000];
ll lcs(string s1,string s2)
{
    ll i,j;
    ll mx=0;
    for(i=0; i<=s1.length(); i++)
    {
        for(j=0; j<=s2.length(); j++)
        {
            if(i==0||j==0)
            {
                a[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                a[i][j]=a[i-1][j-1]+1;
                mx=max(mx,a[i][j]);
            }
            else
            {
                a[i][j]=0;
            }
        }
    }
    return mx;
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
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[7000][7000];
string lcs(string s1,string s2)
{
    ll i,j;
    ll mx=0;
    for(i=0; i<=s1.size(); i++)
    {
        for(j=0; j<=s2.size(); j++)
        {
            if(i==0||j==0)
            {
                a[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                a[i][j]=a[i-1][j-1]+1;
                mx=max(mx,a[i][j]);
            }
            else
            {
                a[i][j]=0;
            }
        }
    }
    if(mx==0)return "0";
   /* for(i=0;i<=s1.size();i++)
    {
        for(j=0;j<=s1.size();j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/
    string s="";
     for(i=0;i<=s1.size();i++)
    {
        for(j=0;j<=s1.size();j++)
        {
            if(a[i][j]==mx)
            {
                while(a[i][j]!=0)
                {
                    i--;
                    j--;
                    s+=s1[i];
                }
                reverse(s.begin(),s.end());
                return s;
            }
        }
    }
}
void solve()
{
    ll n,m,j=0,y,i,k,x,c,d,l,r,mod=1e9+7;
    string s1,s2,s;
    cin>>s2>>s1;
    s=lcs(s1,s2);
    cout<<s<<endl;
}
int main()
{
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}

