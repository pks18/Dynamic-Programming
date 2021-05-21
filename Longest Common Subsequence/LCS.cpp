#include <cstdlib>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int lcs(string a,string b,int x,int y)                  //recursive solution
{
    if(x>=0 and y>=0)
        if(a[x]==b[y])
            return 1+lcs(a,b,x-1,y-1);
        else
            return max(lcs(a,b,x-1,y),lcs(a,b,x,y-1));
    else
        return 0;
}
int lcsiter(string a,string b,int x,int y)              //bottom-up approach
{
    int dp[x+1][y+1];
    for(int i=0;i<x+1;++i)
        dp[i][0]=0;
    for(int i=0;i<y+1;++i)
        dp[0][i]=0;
    for(int i=1;i<x+1;++i)
        for(int j=1;j<y+1;++j)
            if(a[i-1]==b[j-1])dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    
    for(int i=0;i<x+1;++i)
    {
        for(int j=0;j<y+1;++j)
            cout<<dp[i][j]<<" ";
        cout<<'\n';
    }
    
    return dp[x][y]; 
}
int dp[50][50];
int lcsrec(string a,string b,int x,int y)              //top-down approach
{
    if(dp[x][y]<0)
    {
        if(a[x-1]==b[y-1])
            dp[x][y]=1+lcsrec(a,b,x-1,y-1);
        else
            dp[x][y]=max(lcsrec(a,b,x,y-1),lcsrec(a,b,x-1,y));
        return dp[x][y];
    }
    else
        return dp[x][y];
}
int lcssp(string a,string b,int x,int y)               //better space complexity-iterative
{
    int dp[2][y+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<x+1;++i)
    {
        for(int j=1;j<y+1;++j)
            if(a[i-1]==b[j-1])
                dp[1][j]=1+dp[0][j-1];
            else
                dp[1][j]=max(dp[1][j-1],dp[0][j]);
        for(int j=1;j<y+1;++j)
            dp[0][j]=dp[1][j];
        cout<<'\n';
    }
    return dp[1][y];
}
int lcsrsp(string a,string b,int x,int y)               //best space complexity-iterative
{
    int dp[y+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<x+1;++i)
    {
        int pred = 0;
        for(int j=1;j<y+1;++j)
        {
            int pre=dp[j];
            if(a[i-1]==b[j-1])
            {
                dp[j]=1+pred;
                pred = pre;
            }    
            else
            {
                pred = dp[j];
                dp[j]=max(dp[j-1],pre);
            }
        }
    }
    return dp[y];
}
int main()
{
    string a,b;
    cin>>a>>b;
    //a="ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    //b="GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    int x=a.length(),y=b.length();
    //cout<<lcs(a,b,x-1,y-1);               //call to recursive function
    //cout<<lcsiter(a,b,x,y)<<'\n';           //call to iterative function-tabulation    
    
    //pre-processing required for memoization method
    
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<x+1;++i)
        dp[i][0]=0;
    for(int i=0;i<y+1;++i)
        dp[0][i]=0;
    cout<<lcsrec(a,b,x,y)<<'\n';            //call to memoization method
    for(int i=0;i<x+1;++i)
    {
        for(int j=0;j<y+1;++j)
            cout<<dp[i][j]<<" ";
        cout<<'\n';
    }
    string ans;
    while(dp[x][y]!=0)
    {
        if(dp[x][y]==dp[x-1][y])                            //Skipping those locations where value inherited from 
            x--;
        else if(dp[x][y]==dp[x][y-1])                       // top or left
            y--;
        else
        {
            ans.push_back(a[x-1]);                          //Adding those locations character where value was updated.
            x--;
            y--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<'\n';
    
    
    //cout<<lcssp(a,b,x,y)<<'\n';             //Reduced space complexity :O(x+y)(iterative version)
    //cout<<lcsrsp(a,b,x,y)<<'\n';              //Ultimate reduced space complexity version of lcs
    return 0;
}

