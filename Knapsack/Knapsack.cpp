#include<bits/stdc++.h>
using namespace std;
//A pure recursive solution
int knapsack(vector<pair<int,int>>&items,int capacity,int n)
{
    if(n==0||capacity==0)
        return 0;
    if(items[n-1].second > capacity)
        return knapsack(items,capacity,n-1);
    else
        return max(items[n-1].first+knapsack(items,capacity-items[n-1].first,n-1),knapsack(items,capacity,n-1));
}

//A bottom-up approach
int knapsack_btu(vector<pair<int,int>>&items,int capacity, int n)
{
    vector<vector<int>>dp(n+1,vector<int>(capacity+1,0));
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=capacity;++j)
        {
            if(items[i-1].second<=j)
            {
                dp[i][j] = max(dp[i-1][j],items[i-1].first+dp[i-1][j-items[i-1].second]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
//    for(int i=0;i<=n;++i)
//    {
//        for(int j=0;j<=capacity;++j)
//        {
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<'\n';
//    }
//    
    cout<<"Items selected:\n";
    int i=n,j=capacity;
    vector<pair<int,int>>ans;
    while(dp[i][j]!=0)
    {
        if(dp[i-1][j]==dp[i][j])
            i--;
        else
        {
            ans.push_back(items[i-1]);
            j = j-items[i-1].second;
            i--;            
        }
    }
    for(auto i:ans)
        cout<<i.second<<" "<<i.first<<'\n';
    return dp[n][capacity];
}

int main()
{
    int capacity;
    cin>>capacity;
    int n;
    cin>>n;
    vector<pair<int,int>>items(n);
    for(int i=0;i<n;++i)
    {
        cin>>items[i].second>>items[i].first;
    }
    //cout<<knapsack(items,capacity,n);
    
    cout<<knapsack_btu(items,capacity,n);
    return 0;
}


