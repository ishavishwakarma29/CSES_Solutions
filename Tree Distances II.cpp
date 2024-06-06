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
vector<int> primeFactors(int n)
{
    vector<int> v;
    // Print the number of 2s that divide n 
    while (n % 2 == 0)
    {
        v.push_back(2);
        n = n/2;
    }
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n 
        while (n % i == 0)
        {
            v.push_back(i);
            n = n/i;
        }
    }
    // This condition is to handle the case when n
    // is a prime number greater than 2 
    if (n > 2) 
        v.push_back(n);
    return v;

}
vector<int> printDivisors(int n) 
{
    vector<int> v;
    // Note that this loop runs till square root
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                v.push_back(i);
            else{ // Otherwise print both
                v.push_back(i);
                v.push_back(n/i);
            }
        }
    }
    return v;
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
int n;
vector<int> graph[200001];
int dp[200001], ans[200001];
void dfs1(int node = 1, int parent = 0, int depth = 0)
{
    ans[1] += depth;
    dp[node] = 1;
    for (int i : graph[node])
        if (i != parent) 
        {
            dfs1(i, node, depth + 1);
            dp[node] += dp[i];
        }
}
void dfs2(int node = 1, int parent = 0)
{
    for (int i : graph[node])
        if (i != parent) 
        {
            ans[i] = ans[node] + n - 2 * dp[i];
            dfs2(i, node);
        }
}
int32_t main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
        cin>>n;
        int e=n-1;
        for(int i=1; i<=e; i++)
        {
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs1();
        dfs2();
        for(int i=1; i<=n; i++){
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}
