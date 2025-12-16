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
    vector<ll>dp(n+1);// dp[i] -> max sum attained by first i cows
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=-MOD;
        ll maxi=arr[i-1];
        // the last group can be of size [1,k]..
        //so we iterate on all possibilities
        for(int j=i-1;j>=0&&j>=i-1-k+1;j--)
        {
            maxi=max(maxi,arr[j]);
            dp[i]=max(dp[i],dp[j]+(i-j)*1ll*maxi);
        }
    }
    cout<<dp[n]<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("teamwork.in", "r", stdin);
    //freopen("teamwork.out", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
}