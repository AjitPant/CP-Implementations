//--------PREPROCESSOR--------PREPROCESSOR--------PREPROCESSOR--------PREPROCESSOR--------PREPROCESSOR--------PREPROCESSOR--------PREPROCESSOR
    
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define REDL(a ,n) vll a(n);for(ll i=0;i<n;i++) cin>>a[i];
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(X)  X.begin() ,  X.end()
#define reset(X) memset(X, 0, sizeof(X))
#define endl '\n'
#define int long long
//-----------------------------TEMPLATES------------------TEMPLATES---------------------------TEMPLATES---------------------------------
//-----------------------------TEMPLATES------------------TEMPLATES---------------------------TEMPLATES---------------------------------
    
//--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF----------------------------TYPEDEF
//--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF--------------TYPEDEF----------------------------TYPEDEF
    
typedef  long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ll,ll> pii;
typedef vector<ll> vll;
typedef vector<int> vi;    
    
//--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS
//--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS--------------CONSTANTS
    
const ll INF=1e18;
const ll mod=1000000007;
const ld PI=acos(-1);    
    
    
    
    
    
//------------------IGNOREABLE_CONTENT------------------IGNOREABLE_CONTENT------------------IGNOREABLE_CONTENT------------------IGNOREABLE_CONTENT
    
    
    
// To find GCD of a and b
ll gcd(ll a, ll b);
    
// To compute x raised to power y under modulo m
    // To compute x^y under modulo m
int power(int x,  int y, int p) 
{ 
    int res = 1;      // Initialize result 
    
    x = x % p;  // Update x if it is more than or  
                // equal to p 
    
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
    
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
}
// Function to find modular inverse of a under modulo m
// Assumption: m is prime
ll modInverse(ll a, ll m=mod)
{
    ll g =1;
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // If a and m are relatively prime, then modulo inverse
        // is a^(m-2) mode m
        return power(a, m-2, m);
    }
}
    
    
// Function to return gcd of a and b
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
//------------------WORK--------------------
void fft(vector<complex<ld> >& a, bool invert)
{
    int n=a.size();
    for(int i=1, j=0;i<n ;i++)
    {
        int bit=n>>1;
        for(;j&bit;bit>>=1)
            j^=bit;
        j^=bit;
        if(i<j)
            swap(a[i], a[j]);
    }
    for(int len=2;len<=n;len<<=1)
    {
        ld ang=2*PI/len*(invert?-1:1);
        complex<ld> mult=complex<ld>(cos(ang), sin(ang));
        for(int i=0;i<n;i+=len)
        {
            complex<ld> w=1;
            for(int j=i;j<i+len/2;j++)
            {
                auto u=a[j]+w*a[j+len/2];
                auto v=a[j]-w*a[j+len/2];
                a[j]=u;
                a[j+len/2]=v;    
                w*=mult;
            }
        }
    }
    if(invert)
        for(auto&i:a)
            i/=n;
}
vector<int>  multiply(vector<int> a, vector<int> b)
{
    int n=1;
    while(n<a.size()+b.size())
        n*=2;
    vector<complex<ld>> A(a.begin(), a.end()), B(all(b));
    A.resize(n);
    B.resize(n);
    fft(A, false);
    fft(B,false);
    for(int i=0;i<n;i++)
        A[i]*=B[i];
    fft(A, true);
    vector<int> result(n);
    for(int i=0;i<n;i++)
        result[i]=round(A[i].real());
    return result;
}
//----------------------MAIN______________________________MAIN__________________MAIN


    
signed main()
{
    
    
    auto start = high_resolution_clock::now();

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cout.tie(0);
        
    #ifndef ONLINE_JUDGE
        freopen ("INPUT.txt" , "r" , stdin);
        // freopen ("OUTPUT.txt" , "w" , stdout);
    #endif
//-----------------------------------------------------------------------------------------------------------
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        n++;
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int j=0;j<n;j++)
            cin>>b[j];
        reverse(all(a));
        reverse(all(b));
        auto ans=multiply(a, b);
        for(int i=0;i<=2*n-2;i++)
            cout<<ans[2*n-2-i]<<" ";
        cout<<endl;
    }
//----------------------------------------------------------------------------------------------------------
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    //  cerr <<endl<<"Time in microseconds:" <<duration.count() <<endl<<"Time in seconds:"<<duration.count()/(1000000.0)<< endl;
}
    
    
