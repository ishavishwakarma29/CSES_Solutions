#include<bits/stdc++.h>
using namespace std;
// -----------------------------------------------------macros------------------------------------------------------------------
#define int long long int
#define vi vector<int>
#define pb push_back
#define in(a, b, arr) for(int i = a; i < b; i++){cin>>arr[i];}
#define out(a, b, arr) for(int i = a; i < b; i++){cout<<arr[i]<<' ';}cout<<endl;

int solve(int vertex, bool isIncluded, vector<int>* gr, int par, vector<vector<int>>& dp)
{
    if(dp[vertex][isIncluded]!=-1)
    {
        return dp[vertex][isIncluded];
    }

    if(isIncluded)
    {
        int ans=0;
        for(int nbr : gr[vertex])
        {
            if(nbr!=par)
            {
                ans+=solve(nbr, 1, gr, vertex, dp);
            }
        }
        int myRes=0;
        for(int nbr : gr[vertex])
        {
            if(nbr!=par)
            {
                myRes=max(myRes, 1+ans-dp[nbr][1]+solve(nbr, 0, gr, vertex, dp));
            }
        }

        dp[vertex][isIncluded]=myRes;
        return myRes;
    }
    else
    {
        int ans=0;
        for(int nbr : gr[vertex])
        {
            if(nbr!=par)
            {
                ans+=max(solve(nbr, 1, gr, vertex, dp), solve(nbr, 0, gr, vertex, dp));
            }
        }
        dp[vertex][isIncluded]=ans;
        return ans;
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
       vector<vector<int>> dp(n+1, vector<int>(2, -1));
        cout<<max(solve(1, 0, gr, -1, dp), solve(1, 1, gr, -1, dp))<<endl;
    }
    return 0;
}
