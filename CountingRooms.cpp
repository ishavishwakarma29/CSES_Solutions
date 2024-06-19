#include<bits/stdc++.h>
using namespace std;
// -----------------------------------------------------macros------------------------------------------------------------------
#define int long long int
#define vi vector<int>
#define pb push_back
#define in(a, b, arr) for(int i = a; i < b; i++){cin>>arr[i];}
#define out(a, b, arr) for(int i = a; i < b; i++){cout<<arr[i]<<' ';}cout<<endl;

void dfs(int i, int j, int n, int m, vector<vector<int>>& vis, vector<vector<char>>& mat)
{
    if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || mat[i][j]=='#')
    {
        return;
    }
    vis[i][j]=1;
    dfs(i+1, j, n, m, vis, mat);
    dfs(i, j+1, n, m, vis, mat);
    dfs(i-1, j, n, m, vis, mat);
    dfs(i, j-1, n, m, vis, mat);
}

int32_t main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>mat[i][j];
            }
        }
        int ans=0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]=='.' && !vis[i][j])
                {
                    dfs(i, j, n, m, vis, mat);
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
