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


struct segmentTree{
    int n;
    vector<int> st;


    void init(int _n)
    {
        this->n = _n;
        st.resize(4*n, 0);
    }

    void build(int start, int ending, int node, vector<int>& v)
    {
        if (start==ending)
        {
            st[node] = v[start];
            return;
        }
        

        int mid = start + (ending-start)/2;
        // left subtree is (start, mid)

        build(start, mid, 2*node+1, v);

        // right subtree is (mid+1, ending)

        build(mid+1, ending, 2*node+2, v);

        st[node] = min(st[node*2 + 1], st[node*2 + 2]);
    }

    int query(int start, int ending, int l, int r, int node)
    {
        // non overlapping case
        if (start>r || ending<l)
        {
            return 1e9+7;
        }
        
        // complete overlap
        if (start>=l && ending<=r)
        {
            return st[node];
        }
        
        int mid = start + (ending-start)/2;

        int q1 = query(start, mid, l, r, 2*node+1);
        int q2 = query(mid+1, ending, l, r, 2 * node + 2);

        return min(q1, q2);
    }

    void update(int start, int ending, int node, int index, int value)
    {
        if (start == ending)
        {
            st[node] = value;
            return;
        }

        int mid = start + (ending - start) / 2;

        if (index<=mid)
        {
            update(start, mid, 2*node+1, index, value);
        }

        else
        {
            update(mid+1, ending, 2*node+2, index, value);
        }

        st[node] = min(st[node * 2 + 1], st[node * 2 + 2]);
        return;
    }
    void build(vector<int>& v)
    {
        build(0, v.size()-1, 0, v);
    }

    int query(int l, int r)
    {
        return query(0, n-1, l, r, 0);
    }

    void update(int x, int y)
    {
        update(0, n-1, 0, x, y);
    }
}tree;

//------------------------------------------------------------------main function---------------------------------------
int32_t main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector<int> arr(n);
        in(0, n, arr);
        segmentTree tree;
        tree.init(n);
        tree.build(arr);
        while (q--)
        {
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            cout<<tree.query(a, b)<<endl;
        }
        
    }
    return 0;
}
