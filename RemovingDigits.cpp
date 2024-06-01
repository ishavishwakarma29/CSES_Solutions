#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> dp(n+1, 1e9+7);
        dp[0]=0;
        for (int i = 1; i <= n; i++)
        {
           int x=i;
           vector<int> c;
           while (x>0)
           {
                int r=x%10;
                x/=10;
                c.push_back(r);
           }
           for(int j=0; j<c.size(); j++)
           {
            if(i-c[j]>=0)
            dp[i]=min(dp[i], 1+dp[i-c[j]]);
           }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
