#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isSubsetSum(ll set[],ll n,ll sum)
{
    bool dp[n + 1][sum + 1];

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    // Fill the subset table in botton up manner
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < set[i - 1])
                dp[i][j] = dp[i - 1][j];
            if (j >= set[i - 1])
                dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - set[i - 1]]);
        }
    }

     for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= sum; j++)
          printf ("%4d", dp[i][j]);
       printf("\n");
     }

    return dp[n][sum];
}
void solve()
{
    vector<ll>v,v1;
    map<ll,ll>mp;
    ll n,m,j,i,k,len,z,p,x,y;
    cin>>n;
    ll a[n+2];
    ll sum=0;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    /*if(sum%2!=0)
    {
        cout<<"NO"<<endl;
        return;
    }*/
    if(isSubsetSum(a,n,sum/2))
    {
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;

}
int main()
{
    int T=1;
   // cin>>T;
    while(T--)solve();
    return 0;
}

 bool dfs(int idx,int n,int a[],int target,vector<vector<int>>&dp)
    {
        if(target==0)return 1;

        if(target<0 || idx>=n)return 0;

        if(dp[idx][target]!=-1)return dp[idx][target];

        bool take=dfs(idx+1,n,a,target-a[idx],dp);

        bool ntake=dfs(idx+1,n,a,target-0,dp);

        return dp[idx][target]=take|ntake;
    }
    int equalPartition(int N, int arr[])
    {
        int i,j;
        int sum=0;
        for(i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        if(sum&1)return 0;

        vector<vector<int>>dp(N+1,vector<int>(sum,-1));

        return dfs(0,N,arr,sum/2,dp);

    }
