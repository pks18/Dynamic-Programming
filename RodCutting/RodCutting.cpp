#include<bits/stdc++.h>
#include <chrono>
#define ll long long
#define N 1000000007
using namespace std;
using namespace std::chrono; 

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    vector<int>dp(n+1,0);
    for(int i=1;i<=n;++i)
    {
        dp[i] = a[i-1];
        for(int j=1;j<i;++j)
            if(dp[i]<dp[j]+dp[i-j])
                dp[i]=dp[j]+dp[i-j];
    }
    cout<<"DP Table:\n";
    for(int i=0;i<=n;++i)
        cout<<dp[i]<<" ";
    cout<<'\n';
    cout<<dp[n];
}