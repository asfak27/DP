///     Target Sum    ////

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll isSubsetSum(ll set[],ll n,ll sum)
{
    ll dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= sum; i++)
        dp[0][i] = 0;

    // Fill the subset table in botton up manner
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < set[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            if (j >= set[i - 1])
            {
                dp[i][j] = (dp[i - 1][j]+dp[i - 1][j - set[i - 1]]);
            }
        }
    }

   /* for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= sum; j++)
          printf ("%4d", dp[i][j]);
       printf("\n");
     }*/

    return dp[n][sum];
}
void solve()
{
    vector<ll>v,v1;
    map<ll,ll>mp;
    ll n,m,j,i,k,len,z,p,x,y;
    cin>>n>>k;
    ll a[n+2];
    ll sum=0;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    m=(k+sum)/2;
    x=isSubsetSum(a,n,m);
    cout<<x<<endl;
}
int main()
{
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}

