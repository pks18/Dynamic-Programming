#include <cstdlib>
#include <bits/stdc++.h>
#define ll long long
#define infinity INT_MAX
#define minfinity INT_MIN
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    //O(n^2) approach
/*    vector<int>length(n,1),previous(n,0);
    for(int i=0;i<n;++i)
    {
        previous[i] = i;
        for(int j=i-1;j>=0;--j)
        {
            if(a[j]<a[i] and length[i]<length[j]+1)
            {
                length[i] = length[j]+1;
                previous[i] = j;
            }
        }
    }
    int index=0;
    for(int i=0;i<n;++i)
    {
        if(length[i]>length[index])
        {
            index = i;
        }
    }
    cout<<length[index]<<'\n';
    vector<int>ans;
    do
    {
        ans.push_back(a[index]);
        index = previous[index];
    }while(previous[index]!=index);
    ans.push_back(a[index]);
    reverse(ans.begin(),ans.end());
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<'\n';
*/
    /*
     It is also possible to restore the subsequence without the auxiliary array p[]. 
     We can simply recalculate the current value of d[i] and also see how the maximum was reached.
    */
    
    //O(nlogn) approach
    vector<int>dp(n+1,infinity),r(n,-1),ind(n,-1);
    dp[0] = minfinity;
    for(int i=0;i<n;++i)
    {
        int j = upper_bound(dp.begin(),dp.end(),a[i])-dp.begin();
        if(dp[j-1]<a[i] and dp[j]>a[i])
        {
            dp[j] = a[i];
            ind[j] = i;
            r[i] = ind[j-1];
        }
    }
    int ans=0;
    for(int i=0;i<n+1;++i)
        if(dp[i]!=infinity)
            ans = i;
    cout<<ans<<'\n';
//    for(int i=0;i<n;i++)
//        cout<<ind[i]<<" ";
//    cout<<'\n';
//    for(int i=0;i<n;i++)
//        cout<<r[i]<<" ";
//    cout<<'\n';

    vector<int>s;
    ans = ind[ans];
    while(ans!=-1)
    {
        s.push_back(a[ans]);
        ans = r[ans];
    }
    reverse(s.begin(),s.end());
    for(auto i:s)
        cout<<i<<" ";
    cout<<'\n';
    return 0;
}

