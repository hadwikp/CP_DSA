//https://usaco.org/index.php?page=viewproblem2&cpid=971
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int MOD=1e9+7;
const int MOD1=998244353;
const ll INF=LONG_LONG_MAX/2;
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    string s; cin>>s;
    vector<vector<int>> cost(m,vector<int>(m,0));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++) cin>>cost[i][j];
    }
    //floyd-warshall
    for(int t=0;t<m;t++)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++) cost[i][j]=min(cost[i][j],cost[i][t]+cost[t][j]); 
        }
    }
    vector<int> dpmin(n,INF);
    vector<vector<int>> dp(n,vector<int>(m));
    vector<vector<int>> change_pref(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        int curr=s[i]-'a';
        for(int to=0;to<m;to++)
        {
            change_pref[i][to]=((i==0)?0:change_pref[i-1][to])+cost[curr][to];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dp[i][j]=((i==0)?0:dp[i-1][j])+cost[s[i]-'a'][j];
            if(i-k>=0) dp[i][j]=min(dp[i][j],dpmin[i-k]+(change_pref[i][j]-change_pref[i-k][j]));
            //
            if(i>=k-1) dpmin[i]=min(dpmin[i],dp[i][j]);
        }
    }
    cout<<dpmin[n-1]<<"\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
}