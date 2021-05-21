#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
int main() 
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>>d(v,vector<int>(v,inf));
    vector<vector<int>>path(v,vector<int>(v,-1));
    for(int i=0;i<v;++i)
        d[i][i] = 0;
    vector<pair<int,pair<int,int>>>edges(e);
    for(int i=0;i<e;++i)
    {
        cin>>edges[i].second.first>>edges[i].second.second>>edges[i].first;
        path[edges[i].second.first][edges[i].second.second] = edges[i].second.first;
    }
    for(auto i:edges)
    {
        d[i.second.first][i.second.second] = i.first;
    }
    for(int i=0;i<v;++i)
    {
        for(int j=0;j<v;++j)
        {
            if(d[i][j]!=inf)
                cout<<d[i][j]<<" ";
            else
                cout<<"inf ";
        }
        cout<<'\n';
    }
    cout<<'\n';
    for(int k=0;k<v;++k)
        for(int i=0;i<v;++i)
            for(int j=0;j<v;++j)
                if(d[i][j]>d[i][k]+d[k][j] and d[i][k]!=inf and d[k][j]!=inf)
                {
                    d[i][j] = d[i][k]+d[k][j];
                    path[i][j] = path[k][j];
                }
    for(int i=0;i<v;++i)
    {
        for(int j=0;j<v;++j)
        {
            if(d[i][j]!=inf)
                cout<<d[i][j]<<" ";
            else
                cout<<"inf ";
        }
        cout<<'\n';
    }
    cout<<"Predecessor:\n";
    for(int i=0;i<v;++i)
    {
        for(int j=0;j<v;++j)
        {
            cout<<path[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<"Enter the source and destination:\n";
    int s,de;
    cin>>s>>de;
    cout<<"Path from source to destination:";
    vector<int>ans;
    while(de!=s)
    {
        ans.push_back(de);
        de = path[s][de];
    }
    ans.push_back(s);
    reverse(ans.begin(),ans.end());
    for(auto i:ans)
        cout<<i<<" ";
    return 0;
}

