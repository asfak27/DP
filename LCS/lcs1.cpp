#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll lcs(string s1,string s2,ll len1,ll len2)
{
    if(len1==0 || len2==0)
    {
        return 0;
    }
    else if(s1[len1-1]==s2[len2-1])
    {
        return 1+lcs(s1,s2,len1-1,len2-1);
    }
    else{
        return max(lcs(s1,s2,len1,len2-1),lcs(s1,s2,len1-1,len2));
    }
}

void solve()
{
    ll n,m,j=0,y,i,k,x,c,d,l,r,mod=1e9+7;
    string s1,s2;
    cin>>s1>>s2;
    ll len1=s1.size();
    ll len2=s2.size();
    ll res=lcs(s1,s2,len1,len2);
    cout<<res<<endl;
}
int main()
{
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}
