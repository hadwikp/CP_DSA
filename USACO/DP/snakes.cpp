#include <bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;
#define ll long long
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    for(auto &x:arr) cin>>x;

    ll dp[n][k+1];
    //dp[i][j] -> minimum sum of sizes required with k changes
    // final answer  dp[n-1][k] - sigma(arr_i);

    ll max_all=-MOD;
    for(int i=0;i<n;i++)
    {
        max_all=max(max_all,arr[i]);
        for(int j=0;j<=k;j++)
        {
            if(j==0) { dp[i][j]=max_all*1ll*(i+1); continue;}

            ll maxi=arr[i];
            dp[i][j]=MOD;
            for(int t=i;t>=0;t--)
            {
                maxi=max(maxi,arr[t]);
                if(t>0) dp[i][j]=min(dp[i][j],dp[t-1][j-1]+maxi*1ll*(i-t+1));
                else if(t==0) dp[i][j]=min(dp[i][j],maxi*1ll*(i+1));
            }
        }
    }
    ll sum=accumulate(arr.begin(),arr.end(),0ll);
    cout<<dp[n-1][k]-sum<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("snakes.in", "r", stdin);
    //freopen("snakes.out", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
}