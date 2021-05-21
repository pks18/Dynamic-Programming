#include <cstdlib>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
//Pure Recursive Solution
int LPS(string a, int i,int j)
{
    if(i==j)
        return 1;
    if(i>j)
        return 0;
    if(a[i]==a[j])
        return 2+LPS(a,i+1,j-1);
    else
        return max(LPS(a,i,j-1),LPS(a,i+1,j));
}
// A top-down approach
int LPS_tpd(string a,int i,int j,vector<vector<int>>&dp)
{
    if(dp[i][j]!=-1)
        return dp[i][j];
    else
    {
        if(i==j)
            dp[i][j] = 1;
        else if(i>j)
            return 0;
        else if(a[i]==a[j])
            dp[i][j] = 2+LPS_tpd(a,i+1,j-1,dp);
        else
            dp[i][j] = max(LPS_tpd(a,i,j-1,dp),LPS_tpd(a,i+1,j,dp));
    }
    return dp[i][j];
}

//A bottom-up approach
int LPS_btu(string a, vector<vector<int>>&dp)
{
    for(int i=0;i<a.length()-1;++i)
        dp[i][i] = 1;
    for(int l=1;l<a.length();++l)
    {
        for(int i=0,j=i+l;i<a.length()-l;++i,++j)
        {
            if(a[i]==a[j])
                dp[i][j] = 2+dp[i+1][j-1];
            else
                dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
        }
    }
    for(int i=0;i<a.length();++i)
    {
        for(int j=0;j<a.length();++j)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<'\n';
    }
    //Print the Longest Palindromic Subsequence
    string f,ans;
    int i = 0,j = a.length()-1;
    while(!(dp[i][j]==0||dp[i][j]==1))
    {
        //cout<<dp[i][j]<<'\n';
        if(dp[i+1][j]==dp[i][j])
            i++;
        else if(dp[i][j]==dp[i][j-1])
            j--;
        else
        {
            f.push_back(a[i]);i++;j--;
        }
    }        
    ans+=f;
    if(dp[i][j]==1)
        ans.push_back(a[i]);
    reverse(f.begin(),f.end());
    ans+=f;
    cout<<"Longest Palindromic Subsequence:"<<ans<<'\n';    
    return dp[0][a.length()-1];
}

//Alternate Approach: Longest Common Subsequence of string and reverse of string
int LCS_tpd(string a,string b, int i,int j,vector<vector<int>>&dp)
{
    if(dp[i][j]!=-1)
        return dp[i][j];
    else
    {
        if(i==0||j==0)
            dp[i][j] = 0;
        else if(a[i-1]==b[j-1])
            dp[i][j] = 1+LCS_tpd(a,b,i-1,j-1,dp);
        else
            dp[i][j] = max(LCS_tpd(a,b,i-1,j,dp),LCS_tpd(a,b,i,j-1,dp));
        return dp[i][j];
    }
}

int main()
{
    string a,b;
    //cin>>a;
    a="AAAGGTCCGGTCGAGTGCGCGGAAGCCGGCCGAAAACCA";
    b = a;
    reverse(b.begin(),b.end());
    //cout<<LPS(a,0,a.length()-1)<<'\n';
    
    //vector<vector<int>>dp(a.length(),vector<int>(a.length(),-1));
    //cout<<LPS_tpd(a,0,a.length()-1,dp);
    
    vector<vector<int>>dp(a.length(),vector<int>(a.length(),0));
    cout<<LPS_btu(a,dp);
    
    //vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,-1));
    //cout<<LCS_tpd(a,b,a.length(),b.length(),dp);
    return 0;
}

