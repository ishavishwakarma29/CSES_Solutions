#include<bits/stdc++.h>
using namespace std;
 
#define int long long int
#define vi vector<int>
#define pb push_back
#define in(a, b, arr) for(int i = a; i < b; i++){cin>>arr[i];}
#define out(a, b, arr) for(int i = a; i < b; i++){cout<<arr[i]<<;}cout<<endl;
 
void primeSieve(vector<int> &sieve, int N)
{
    sieve[1] = sieve[0] = 0;
    for (int i = 2; i <= N ; i++)
    {
            int p = sieve[i];
            if (p==1)
            {
                for (int j = i*i; j <= N; j = j+i)
                {
                    sieve[j] = 0;
                }
            }
    }
}
 
int32_t main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int ans=1;
        int curr=1;
        for (int i = 0; i < s.length()-1; i++)
        {
            if (s[i]==s[i+1])
            {
                curr++;
            }
            else
            {
                ans=max(ans, curr);
                curr=1;
            }
        }
        ans=max(ans, curr);
        cout<<ans<<endl;
    }
    return 0;
}
