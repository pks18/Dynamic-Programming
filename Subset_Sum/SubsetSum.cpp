#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    int sum;
    cin>>sum;
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
    for(int i=0;i<=n;++i)
        dp[i][0] = true;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=sum;++j)
        {
            if(a[i-1]>j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j]||dp[i-1][j-a[i-1]];
        }
    }
    if(dp[n][sum])
        cout<<"Subset found!";
    else
        cout<<"Subset not found";
    return 0;
}

