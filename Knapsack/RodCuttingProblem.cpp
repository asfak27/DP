#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll unboundedKnapsack(ll W, ll n, ll val[], ll wt[])
{
    ll dp[W+1];
    memset(dp, 0, sizeof dp);

    for (int i=0; i<=W; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (wt[j] <= i)
            {
                dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);
            }
        }
    }
    return dp[W];
}
int main()
{
    ll w,n,i,j;
    cin>>n>>w;
    ll val[n+1],wt[n+1];
    for(i=0; i<n; i++)
    {
        cin>>val[i];
    }
    for(i=0; i<n; i++)
    {
        cin>>wt[i];
    }
    cout<<unboundedKnapsack(w, n, val, wt);

    return 0;
}
