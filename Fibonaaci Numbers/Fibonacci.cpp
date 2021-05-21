#include <cstdlib>
#include<bits/stdc++.h>
#define ll long long
#define dl double
#define ull unsigned long long
#define fl float
using namespace std;

ll fib(ll n)                //Recursive solution
{
    assert(n>=0);
    if(n==0||n==1)
        return n;
    else 
        return fib(n-1)+fib(n-2);
}
ll fibiter(ll n)            // Bottom-up approach
{
    assert(n>=0);
    ll dp[n+1];
    dp[0]=0;
    dp[1]=1;
    for(ll i=2;i<=n;++i)
        dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}
ll dp[91];
ll fibrec(ll n)             // Top-down approach
{
    assert(n>=0);
    dp[0]=0;
    dp[1]=1;
    if(dp[n]>=0)
        return dp[n];
    else
        dp[n]=fibrec(n-1)+fibrec(n-2);
    //cout<<dp[n]<<" ";
    return dp[n];
}
int main() 
{
    int n;
    cin>>n;    
    memset(dp,-1,sizeof(dp));
    cout<<fib(n)<<'\n';
    cout<<fibiter(n)<<'\n';
    cout<<fibrec(n)<<'\n';    
    return 0;
}

