#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
class matrix
{
public:
    int rows,columns,cost;
    matrix(int r,int c)
    {
        rows = r;
        columns = c;
        cost = 0;
    }
    matrix()
    {
        rows = 0;
        columns = 0;
    }
};
matrix multiply(matrix a,matrix b)
{
    matrix ans(a.rows,b.columns);
    ans.cost = a.cost+b.cost+a.rows*a.columns*b.columns;
    return ans;
}
//Top-down approach-Running time O(n^3)
matrix min_cost(vector<matrix>&a,int i,int j,map<pair<int,int>,matrix>& dp)
{
    if(i==j)
        return a[i];
    else if(dp.find(make_pair(i,j))!=dp.end())
    {
        return dp.find(make_pair(i,j))->second;
    }
    else
    {
        matrix ans;
        for(int k=i;k<j;++k)
        {
            matrix left = min_cost(a,i,k,dp);
            matrix right = min_cost(a,k+1,j,dp);
            matrix result = multiply(left,right);        
            if((ans.rows==0 and ans.columns==0)or(ans.cost > result.cost))
                ans = result;
        }
        dp[make_pair(i,j)] = ans;
        return ans;
    }
}
//Pure recursive solution
matrix min_cost(vector<matrix>&a,int i,int j)
{
    if(i==j)
        return a[i];
    else
    {
        matrix ans;
        for(int k=i;k<j;++k)
        {
            matrix left = min_cost(a,i,k);
            matrix right = min_cost(a,k+1,j);
            matrix result = multiply(left,right);        
            if((ans.rows==0 and ans.columns==0)or(ans.cost > result.cost))
                ans = result;
        }
        return ans;
    }
}
//bottom-up approach-time complexity-O(n^3)
int min_cost(vector<matrix>&a)
{
    int n = a.size();
    vector<vector<matrix>>dp(n,vector<matrix>(n));
    for(int i=0;i<n;++i)
    {
        dp[i][i] = a[i];
    }
    for(int length=1;length<n;++length)
    {
        for(int i=0;i<n-length;++i)
        {
            for( int k = i,j = i+length;k < j; k++)
            {
                matrix t = multiply(dp[i][k],dp[k+1][j]);
                if(dp[i][j].rows==0 || (dp[i][j].cost)>t.cost)
                    dp[i][j] = t;
            }
        }
    }
    return dp[0][n-1].cost;
}


int main() 
{
    int n;
    cin>>n;
    vector<matrix>a(n);
    for(int i=0;i<n;++i)
    {
        int r,c;
        cin>>r>>c;
        a[i].rows = r;
        a[i].columns = c;
    }
    map<pair<int,int>,matrix>dp;
    // matrix ans = min_cost(a,0,n-1);
    matrix ans = min_cost(a,0,n-1,dp); // memorization solution
    cout<<ans.cost<<'\n';
    //cout<<min_cost(a);
    return 0;
}

