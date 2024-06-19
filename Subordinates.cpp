#include<bits/stdc++.h>
using namespace std;
// -----------------------------------------------------macros------------------------------------------------------------------
#define int long long int
#define vi vector<int>
#define pb push_back
#define in(a, b, arr) for(int i = a; i < b; i++){cin>>arr[i];}
#define out(a, b, arr) for(int i = a; i < b; i++){cout<<arr[i]<<' ';}cout<<endl;

int dfs(int i, vector<int>* gr, vector<int>& ans)
{
    int cnt=0;
    for(auto nbr : gr[i])
    {
        cnt+=1;
        cnt+=dfs(nbr, gr, ans);
    }
    return ans[i]=cnt;
}

int32_t main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       vector<int> gr[n];
       for(int i=1; i<n; i++)
       {
        int a;
        cin>>a;
        a--;
        gr[a].push_back(i);
       }
       vector<int> ans(n, 0);
       dfs(0, gr, ans);
       out(0, n, ans);
    }
    return 0;
}
