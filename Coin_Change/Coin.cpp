#include<bits/stdc++.h>
#include <cstdlib>
#include<chrono>
using namespace std::chrono;
using namespace std;
#define infty INT_MAX
//Pure recursive solution
int change(int m,vector<int>&coins)
{
    if(m==0)
        return 0;
    else
    {
        int x = INT_MAX;
        for(int i=0;i<coins.size();++i)
        {
            if(m-coins[i]>=0)
                x = min(x,change(m-coins[i],coins));
        }
        return 1+x;
    }
}

//A top-down approach
int change_tpd(int m, vector<int>&coins, vector<int>&dp)
{
    if(dp[m]!=-1)
        return dp[m];
    else if(m==0)
        dp[m] = 0;
    else
    {
        int x = INT_MAX;
        for(int i=0;i<coins.size();++i)
        {
            if(m-coins[i]>=0)
                x = min(x,change_tpd(m-coins[i],coins,dp));
        }
        dp[m] = 1+x;
    }
    return dp[m];
}

//A bottom-up Approach
int change_btu(int m,vector<int>&coins)
{
    vector<int>dp(m+1,infty);
    dp[0] = 0;
    for(int i=1;i<=m;++i)
    {
        for(int j=0;j<coins.size();++j)
        {
            if(i-coins[j]>=0)
                dp[i] = min(dp[i-coins[j]],dp[i]);
        }
        dp[i] = dp[i]+1;
    }
    return dp[m];
}
int main()
{
    int m;
    cin>>m;
    vector<int>coins={1,4,5};
//    auto start = high_resolution_clock::now();
//    cout<<change(m,coins)<<'\n';
//    auto stop = high_resolution_clock::now();
//    auto duration = duration_cast<microseconds>(stop - start);
//    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
    
    vector<int>dp(m+1,-1);
    auto start = high_resolution_clock::now();
    cout <<change_tpd(m,coins,dp)<<'\n';
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
    
    auto start1 = high_resolution_clock::now();
    cout <<change_btu(m,coins)<<'\n';
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1-start1);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
    return 0;
}

