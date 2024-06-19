#include<bits/stdc++.h>
using namespace std;
// -----------------------------------------------------macros------------------------------------------------------------------
#define int long long int
#define vi vector<int>
#define pb push_back
#define in(a, b, arr) for(int i = a; i < b; i++){cin>>arr[i];}
#define out(a, b, arr) for(int i = a; i < b; i++){cout<<arr[i]<<' ';}cout<<endl;

void dfs(int i, int parent, vector<int>* gr, vector<int>& dist)
{
    for(auto nbr : gr[i])
    {
        if(nbr != parent)
        {
            dist[nbr] = dist[i]+1;
            dfs(nbr, i, gr, dist);
        }
    }
}

int32_t main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       vector<int> gr[n+1];
       for(int i=0; i<n-1; i++)
       {
            int u,v;
            cin>>u>>v;
            gr[u].push_back(v);
            gr[v].push_back(u);
       }
       vector<int> dist(n+1);
       dist[1]=0;
       dfs(1, 0, gr, dist);
       int maxi=0, n1=1;
       for (int i = 1; i <= n; i++)
       {
           if (dist[i] > maxi)
           {
               maxi = dist[i];
               n1 = i;
           }
       }
       for (int i = 1; i <= n; i++)
       {
           dist[i] = 0;
       }
       dfs(n1, 0, gr, dist);
       maxi=0;
       for (int i = 1; i <= n; i++)
       {
           maxi=max(maxi, dist[i]);
       }

       cout<<maxi<<endl;
    }
    return 0;
}
