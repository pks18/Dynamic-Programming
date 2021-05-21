#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin>>n>>k;
    ll x;
    map<ll,ll>mp;
    for(ll i=0;i<n;++i)
    {
        cin>>x;
        mp[x]++;
    }
    ll primes = mp.size();
    k = min(k,primes);
    ll dp[primes][primes];
    memset(dp,0,sizeof(dp));
    ll it=0;
    for(auto i:mp)
    {
        dp[0][it]=i.second;
        it++;
    }
    for(ll i=1;i<k;++i)
    {
        ll sum=0;
        for(ll j=i;j<primes;++j)
        {
            sum = (sum+dp[i-1][j-1])%mod;
            dp[i][j] = (sum)*(dp[0][j])%mod;
        }
    }
    ll ans=1;
    for(ll i=0;i<k;++i)
    {
        for(ll j=0;j<primes;++j)
        {
            //cout<<dp[i][j]<<" ";
            ans+=dp[i][j];
            ans%=mod;
        }
        //cout<<'\n';
    }
    cout<<ans<<'\n';
    return 0;
} 