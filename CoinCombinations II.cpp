#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
        int mod=1e9+7;
        int n,x;
        cin>>n>>x;
        vector<int> c;
        for(int i=0; i<n; i++)
        {
            int a;
            cin>>a;
            c.push_back(a);
        }
        vector<int> dp(x+1, 0);
        dp[0]=1;
        for (int i = 0; i < n; i++)
        {
           for(int j=0; j<=x; j++)
           {
             if(j-c[i]>=0)
             {
                 dp[j] += dp[j - c[i]];
                 dp[j]%=mod;
             }
           }
        }
        cout<<dp[x]<<endl;
    }
    return 0;
}
