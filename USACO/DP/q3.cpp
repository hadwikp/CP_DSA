//https://usaco.org/index.php?page=viewproblem2&cpid=621
#include <bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;
#define ll long long
#define int ll
int sum(int n)
{
    return (n*(n+1)*(2*n+1))/6;
}
void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &x:arr) cin>>x;
    //we need to find an index to break the array , to linearise..
    vector<int> pref(n,0);
    for(int i=0;i<n;i++)
    {
        pref[i]+=((i==0)?0:pref[i-1])+arr[i]-1;
    }
    int idx=min_element(pref.begin(),pref.end())-pref.begin();
    idx=(idx+1)%n;
    reverse(arr.begin(),arr.begin()+idx);
    reverse(arr.begin()+idx,arr.end());
    reverse(arr.begin(),arr.end());
    // for(auto &x:arr) cout<<x<<" ";
    // cout<<"\n";
    int pref_sum=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {   
        int t=arr[i];
        ans+=sum(pref_sum+t-1)-sum(pref_sum-1);
        pref_sum+=arr[i]-1;
    }
    cout<<ans<<"\n";
}   
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
}