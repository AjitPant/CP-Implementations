/*author: hyperion_1724
  date:
*/

//Required Libraries

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

//Required namespaces

using namespace std;
using namespace __gnu_pbds;

//Required defines

#define endl '\n'

#define READ(X) cin>>X;
#define READV(X) long long X; cin>>X;
#define READAR(A,N) long long A[N]; for(long long i=0;i<N;i++) {cin>>A[i];}
#define rz(A,N) A.resize(N);
#define sz(X) (long long)(X.size())
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define trav(x,A) for(auto &x:A)
#define veci vector<long long>
#define vecl vector<long long>
#define FORI(a,b,c) for(long long a=b;a<c;a++)
#define FORD(a,b,c) for(long long a=b;a>c;a--)
#define all(X) X.begin(),X.end()
//Required typedefs

typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<long long, null_type, greater<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set1;
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pii;
typedef pair<long, long> pll;

//Required Constants

const long long inf = (long long) 1e18;
const long long MOD = (long long) (1e9 + 7);
const long long INIT = (long long) (1e6 + 1);

//Required Functions

ll power (ll x, ll y,ll MOD=MOD)
{
    if (y == 0)
        return 1;
    ll p = power (x, y / 2,MOD) % MOD;
    p = (p * p) % MOD;

    return (y % 2 == 0) ? p : (x * p) % MOD;
}
ll modInverse (ll a, ll MOD=MOD)
{
    return power (a, MOD - 2,MOD);

}

//Work
const ll p=31;
ll compute_hash(const string &s, const long long MOD)
{
    const ll modulo=MOD;
    ll hash_value=0;
    ll p_pow=1;
    for(auto c:s)
    {
        hash_value=(hash_value+(c-'a'+1)*p_pow)%modulo;
        p_pow=(p_pow*p)%modulo;
    }
    return hash_value;
}
vector<ll> compute_hash2(const string &s,const long long MOD)
{
    const ll modulo=MOD;
    vector<ll> hash_value(s.size(),0);
    ll p_pow=1;
    int i=0;
    for(auto c:s)
    {
        hash_value[i]=(hash_value[max(0,i-1)]+(c-'a'+1)*p_pow)%modulo;
        p_pow=(p_pow*p)%modulo;
        i++;
    }
    return hash_value;
}
signed main()
{
    ios::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    #ifndef ONLINE_JUDGE
    freopen ("INPUT.txt", "r", stdin);
    // freopen ("OUTPUT.txt" , "w" , stdout);
    // freopen ("ERROR.txt" , "w" , stderr);

    #endif
    //start from here
    int t;
    cin>>t;
    while(t--)
    {
        ll n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll MOD1=1e9+7;
        ll MOD2=1e9+21;
        auto hash1=compute_hash2(s,MOD1);
        auto hash2=compute_hash2(s, MOD2);
        vector<pll>  hashes;
        for(int i=0;i<n-k+1;i++)
        {
            ll part1=((MOD1+hash1[i+k-1]-((i==0)?0:hash1[i-1])+MOD1)*(modInverse(power(p, i, MOD1),MOD1)))%MOD1;
            ll part2=((MOD2+hash2[i+k-1]-((i==0)?0:hash2[i-1])+MOD2)*(modInverse(power(p, i, MOD2),MOD2)))%MOD2;
            hashes.pb({part1, part2});

        }
        sort(all(hashes));
        int classes=1;
        for(int i=1;i<n-k+1;i++)
        {
            if(hashes[i]!=hashes[i-1])
                classes++;
        }
        cout<<classes<<"\n";
    }
    return 0;
}
