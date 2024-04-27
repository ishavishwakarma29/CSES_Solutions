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
        int n;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        int cnt=0;
        for (int i = 0; i < n-1; i++)
        {
            if (arr[i+1]<arr[i])
            {
                cnt+=arr[i]-arr[i+1];
                arr[i+1]=arr[i];
            }
            
        }cout<<cnt<<endl;
    }
    return 0;
}
