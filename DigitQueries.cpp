#include<bits/stdc++.h>
using namespace std;
 
 
 
 
// -----------------------------------------------------macros------------------------------------------------------------------
 
 
#define int long long int
#define vi vector<int>
#define pb push_back
#define in(a, b, arr) for(int i = a; i < b; i++){cin>>arr[i];}
#define out(a, b, arr) for(int i = a; i < b; i++){cout<<arr[i]<<' ';}cout<<endl;
 
 
 
 
//------------------------------------------------------ constants ------------------------------------------------------------
 
 
int mod=1e9+7;
 
 
// ------------------------------------------------------basic functions----------------------------------------------------------------
 
 
void primeSieve(vector<int> &sieve, int N)
{
    // mark 1 and 0 as not prime
    sieve[1] = sieve[0] = 0;
    // start from 2 and mark all multiples of ith number(prime) as not prime
    for (int i = 2; i <= N ; i++)
    {
            int p = sieve[i];
            if (p==1)
            {
                for (int j = i*i; j <= N; j = j+i)
                {
                    // marking j as not prime
                    sieve[j] = 0;
                }
            }
    }
}
 
int power(int a,int b)
{
    a%=mod;
    int res=1;
    while(b>0)
    {
        if(b&1)
        res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res%mod;
 
 
}
 
 
// -------------------------------------------------------advanced functions-----------------------------------------------------
 
 
int add(int x, int y)
{
    return (x%mod + y%mod)%mod;
 
}
int subtract(int x, int y)
{
    return (x%mod - y%mod + mod)%mod;
 
}
int multiply(int x, int y)
{
    return ((x%mod)*(y%mod))%mod;
 
}
int divide(int x, int y)
{
    return multiply(x, power(y, mod-2));
 
}
int factorial(int n)
{
    int fact[n+1];
    fact[0]=1;
    for (int i = 1; i <=n; i++)
    {
        fact[i] = multiply(fact[i-1], i);
    }
    return fact[n];
 
}
int inverse(int x)
{
    return power(x, mod-2);
 
}
int nCr(int n, int r)
{
    return multiply(factorial(n), multiply(inverse(factorial(r)), inverse(factorial(n-r))));
 
 
}
 
 
//------------------------------------------------------------------main function---------------------------------------
 
 
int32_t main()
{
    cout<<setprecision(19)<<endl;
    vector<int> v;
    v.push_back(1);
    int curr=9;
    for(int i=0; i<18; i++)
    {
        // v.push_back(curr);
        v.push_back(curr+1);
        curr*=10;
        curr+=9;
    }
    vector<int> pre(v.size());
    pre[0]=0;
    for(int i=1; i<v.size(); i++)
    {
        pre[i]=pre[i-1];
        pre[i]+=i*(v[i]-v[i-1]);
        if(pre[i]>=1e18)
        {
            break;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        int ind=-1;
        for(int i=0; i<v.size()-1; i++)
        {
            if(q>=pre[i] &&  q<=pre[i+1])
            {
                ind=i;
                break;
            }
        }
        int si=v[ind];
        int ei=v[ind+1];
        q-=pre[ind];
        // cout<<q<<endl;
        while (si<=ei)
        {
            // cout<<si<<" "<<ei<<endl;
            int mid=si+(ei-si)/2;
            int x=(mid-v[ind]+1)*(ind+1);
            // cout<<x<<endl;
            if(x>=q)
            {
                ei=mid-1;
            }
            else
            {
                si=mid+1;
            }
        }
        q-=(ei-v[ind]+1)*(ind+1);
        // cout<<q<<endl;
        string s=to_string(ei+1);
        cout<<s[q-1]<<endl;
    }
    return 0;
}
