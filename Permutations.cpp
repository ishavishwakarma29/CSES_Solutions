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
        if (n==1)
        {
            cout<<"1"<<endl;
            continue;
        }
        if (n==4)
        {
            cout<<"2 4 1 3"<<endl;
            continue;
        }
        
        if(n<=3)
        {
            cout<<"NO SOLUTION"<<endl;
            continue;
        }
        vector<int> v(n);
        int curr=n;
        for (int i = 0; i < n; i+=2)
        {
            v[i]=curr;
            curr--;
        }
        for (int i = 1; i < n; i+=2)
        {
            v[i]=curr;
            curr--;
        }
        for (int i = 0; i < n; i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
