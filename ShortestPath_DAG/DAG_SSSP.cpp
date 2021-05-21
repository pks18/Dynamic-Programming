#include<bits/stdc++.h>
#include <cstdlib>
#define inf INT_MAX
using namespace std;
stack<int>order;
void printg(vector<vector<int>>&g)
{
    int k=0;
    for(auto i:g)
    {
        cout<<k++<<":";
        for(auto j:i)
            cout<<j<<" ";
        cout<<'\n';
    }
}
void dfs(vector<vector<int>>&g,int s,vector<bool>&visited)
{
    visited[s]=true;
    for(auto i:g[s])
    {
        if(visited[i]==false)
            dfs(g,i,visited);
    }
    order.push(s);
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>>g(v),cost(v);
    for(int i=0;i<e;++i)
    {
        char a,b;
        int c;
        cin>>a>>b>>c;
        g[a-'A'].push_back(b-'A');
        cost[a-'A'].push_back(c);
    }
    //printg(g);
    char sc;
    cout<<"Enter the source:\n";
    cin>>sc;
    int s = sc-'A';
    vector<bool>visited(v,false);
    for(int i=0;i<v;++i)
        if(visited[i]==false)
            dfs(g,i,visited);
    //cout<<'\n';
    vector<int>toposort;
    while(order.empty()!=true)
    {
        toposort.push_back(order.top());
        order.pop();
    }
    vector<int>distance(v,inf),predecessor(v,-1);
    distance[s]=0;
//    cout<<"Topological Sort:\n";
//    for(int i=0;i<v;++i)
//        cout<<toposort[i]<<" ";
//        cout<<(char)('A'+toposort[i])<<" ";
//    cout<<'\n';
    for(auto i:toposort)
    {
        for(int j=0;j<g[i].size();++j)
        {
            if(distance[g[i][j]]>distance[i]+cost[i][j]  and distance[i]!=inf)
            {
                predecessor[g[i][j]] = i;
                distance[g[i][j]] = distance[i]+cost[i][j];
            }
        }
    }
    cout<<"Shortest Path lengths from source:\n";
    for(int i=0;i<v;++i)
        if(distance[i]!=inf)
            cout<<(char)('A'+i)<<":"<<distance[i]<<'\n';
        else
            cout<<(char)('A'+i)<<":"<<"infinity\n";
    
    return 0;
}

