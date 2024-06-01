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
        int dp[x+1];
        dp[0]=1;
        for (int i = 1; i <= x; i++)
        {
            dp[i]=0;
           for(int j=0; j<n; j++)
           {
             if(i-c[j]>=0)
             {
                 dp[i] += dp[i - c[j]];
                 dp[i]%=mod;
             }
           }
        }
        cout<<dp[x]<<endl;
    }
    return 0;
}
