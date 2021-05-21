#include<bits/stdc++.h>
#include <cstdlib>
#include <chrono>
using namespace std::chrono;
#define ll long long 
using namespace std;
//Pure recursive solution
ll binomial(ll n,ll k)
{
    if(n==k||k==0)
        return 1;
    else
        return binomial(n-1,k)+binomial(n-1,k-1);
}

//A top-down approach
ll binomial_tpd(ll n,ll k, vector<vector<ll>>&dp)
{
    if(k==0||n==k)
    {
        dp[n][k]=1;
        return 1;
    }
    else if(dp[n][k]!=-1)
        return dp[n][k];
    else
    {
        dp[n][k] = binomial_tpd(n-1,k,dp)+binomial_tpd(n-1,k-1,dp);
        return dp[n][k];
    }
}

//A bottom up approach
ll binomial_btu(ll n,ll k, vector<vector<ll>>&dp)
{
    for(ll i=2;i<=n;++i)
    {
        for(ll j=1;j<=min(i,k);++j)
        {
            if(j!=i)
            dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
        }
    }
//    for(int i=0;i<n+1;++i)
//    {
//        for(int j=0;j<k+1;++j)
//        {
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<'\n';
//    }
    return dp[n][k];
}
int main()
{
    ll n,k;
    cin>>n>>k;
//    auto start = high_resolution_clock::now();
//    cout<<binomial(n,k)<<'\n';
//    auto stop = high_resolution_clock::now();
//    auto duration = duration_cast<microseconds>(stop - start);
//    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
    
//    vector<vector<ll>>dp(n+1,vector<ll>(k+1,-1));
//    auto start = high_resolution_clock::now();
//    cout<<binomial_tpd(n,k,dp)<<'\n';
//    auto stop = high_resolution_clock::now();
//    auto duration = duration_cast<microseconds>(stop - start);
//    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
//    
    
    vector<vector<ll>>dp(n+1,vector<ll>(k+1,1));
    auto start = high_resolution_clock::now();
    cout<<binomial_btu(n,k,dp)<<'\n';
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
    
    return 0;
}



//A top-down approach
//ll binomial_tpd(ll n,ll k,unordered_map<pair<ll,ll>,ll>mp)
//{
//    //cout<<"*";
//    if(k==0||n==k)
//        return 1;
//    else if(mp.find(make_pair(n,k))!=mp.end())
//    {
//        return mp.find(make_pair(n,k))->second;
//    }
//    else
//    {
//        ll b = binomial_tpd(n-1,k-1,mp)+binomial_tpd(n-1,k,mp);
//        mp[make_pair(n,k)] = b;
//        return b;
//    }
//}
