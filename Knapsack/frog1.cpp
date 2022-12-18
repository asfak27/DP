#include <iostream>
#include <vector>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    const int INF = 1e9;
    // dp[i] : min cost to reach i
    vector<int> dp(n, INF);
   //int dp[n+1];
    dp[0] = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<=i+k; j++)
        {
            if(j<n) dp[j] = min(dp[j], dp[i]+abs(a[i]-a[j]));
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    cout << dp[n-1] << '\n';

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define  no               cout<<"No"<<endl
#define  yes              cout<<"Yes"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
void solve()
{
    ll n,m,j,i,x,y,z,k;  ///   5 10 5 15 5
    cin>>n;
    ll a[n+1],b[n+3];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n==2)
    {
        cout<<abs(a[0]-a[n-1])<<endl;
        return;
    }
    ll mn=1e9;
    b[0]=0;
    b[1]=abs(a[1]-a[0]);
    for(i=2;i<n;i++)
    {
        x=b[i-1]+abs(a[i]-a[i-1]);
        y=b[i-2]+abs(a[i]-a[i-2]);
        b[i]=min(x,y);
    }
    for(i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    cout<<b[n-1]<<endl;
}
int main()
{
    fast;
    int T=1;
   // cin>>T;
    while(T--)solve();
    return 0;
}

