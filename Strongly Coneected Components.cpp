#include<bits/stdc++.h>
#define deb(x) cout<<#x<<" = "<<x<<endl;
using namespace std;
vector<int> g1[100005];
vector<int> g2[100005];
stack<int> s;
int vis[100005];
int vis2[100005];
vector<int> vp;
void dfs(int n,vector<int> g[])
{
    if (!vis[n])
        vis[n]=1;
    for (int i:g[n])
    {
        if(!vis[i])
            dfs(i,g);
    }
    s.push(n);
}

void dfs2(int n, vector<int> g[])
{
    if (!vis2[n])
    {
        vp.push_back(n);
        vis2[n]=1;
    }
    for (int i:g[n])
    {
        if(!vis2[i])
            dfs2(i,g);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
        g1[u].push_back(v);
        g2[v].push_back(u);
    }
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=n; i++)
    {
        if (!vis[i])
            dfs(i,g1);
    }
    int ans=0;
    memset(vis2,0,sizeof(vis2));
    while(!s.empty())
    {
        int i=s.top();
        s.pop();
        vp.clear();
        if (!vis2[i])
        {
            dfs2(i,g2);
            int size=vp.size();
            ans=max(ans,size);
        }
    }
    cout<<ans<<endl;
}