#include<bits/stdc++.h>
using namespace std;
// -----------------------------------------------------macros------------------------------------------------------------------
#define int long long int
#define vi vector<int>
#define pb push_back
#define in(a, b, arr) for(int i = a; i < b; i++){cin>>arr[i];}
#define out(a, b, arr) for(int i = a; i < b; i++){cout<<arr[i]<<' ';}cout<<endl;

void dfs(int i, vector<bool>& vis, vector<int>* gr)
{
    vis[i]=true;
    for(auto nbr : gr[i])
    {
        if(!vis[nbr])
        {
            dfs(nbr, vis, gr);
        }
    }
}

int32_t main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
       int n,m;
       cin>>n>>m;
       vector<int> gr[n+1];
        for (int i = 0; i < m; i++)
        {
           int u,v;
           cin>>u>>v;
           gr[u].push_back(v);
           gr[v].push_back(u);
        }
        vector<bool> vis(n+1, false);
        int cnt=0;
        vector<int> nodes;
        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                nodes.push_back(i);
                dfs(i, vis, gr);
                cnt++;
            }
        }
        cout<<cnt-1<<endl;
        for(int i=0; i<nodes.size()-1; i++)
        {
            cout<<nodes[i]<<" "<<nodes[i+1]<<endl;
        }
    }
    return 0;
}
