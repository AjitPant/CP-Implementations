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
#define veci vector<int>
#define vecl vector<long long>
#define FORI(a,b,c) for(long long a=b;a<c;a++)
#define FORD(a,b,c) for(long long a=b;a>c;a--)

//Required typedefs

typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<long long, null_type, greater<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set1;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

//Required Constants

const long long inf = (long long) 1e18;
const long long MOD = (long long) (1e9 + 7);
const long long INIT = (long long) (1e6 + 1);

//Required Functions

ll power (ll x, ll y)
{
    if (y == 0)
        return 1;
    ll p = power (x, y / 2) % MOD;
    p = (p * p) % MOD;

    return (y % 2 == 0) ? p : (x * p) % MOD;
}
ll modInverse (ll a)
{
    return power (a, MOD - 2);

}

//Work
vector<int> sort_cyclic_shifts (string const& s)
{
    int n = s.size();
    const int alphabet = 256;
    vector<int> p (n), c (n), cnt (max (alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i - 1];
    for(int i=0;i<n;i++)
        p[--cnt[s[i]]]=i;
    c[p[0]]=0;
    int classes=0;
    for(int i=1;i<n;i++)
    {


        if(s[p[i]]!=s[p[i-1]])
            classes++;
        c[p[i]]=classes-1;
    }
    vector<int> pn(n), cn(n);
    for(int h=0;(1<<h)<n;++h)
    {
        for(int i=0;i<n;i++)
        {
            pn[i]=p[i]-(1<<h);
            if(pn[i]<0)
                pn[i]+=n;
        }
        fill(cnt.begin() , cnt.begin()+classes,0);
        for(int i=0;i<n;i++)
            cnt[c[pn[i]]]++;
        for(int i=1;i<classes;i++)
            cnt[i]+=cnt[i-1];
        for(int i=n-1;i>=0;i--)
            p[--cnt[c[pn[i]]]]=pn[i];
        cn[p[0]]=0;
        classes=1;
        for(int i=1;i<n;i++)
        {

            pair<int,int> cur={c[p[i]], c[(p[i]+(1<<h))%n]};
            pair<int,int> prev={c[p[i-1]], c[(p[i-1]+(1<<h))%n]};
            if(cur!=prev)
                ++classes;
            cn[p[i]]=classes-1;
        }
        c.swap(cn);
    }
    return p;

}
vector<int> suffix_arary_construction(string s)
{
    s+="$";
    vector<int> sorted_shifts=sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;

}

vector<int> lcp_construction(string const& s, vector<int> const&p)
{
    int n=s.size();
    vector<int> rank(2*n,0);
    for(int i=0;i<n;i++)
        rank[p[i]]=i;
    int k=0;
    vector<int> lcp(n-1,0);
    for(int i=0;i<n;i++)
    {

        if(rank[i]==n-1)
        {
            k=0;
            continue;
        }
        int j=p[rank[i]+1];
        while(i+k<n&& j+k<n&&s[i+k]==s[j+k])
            k++;
        lcp[rank[i]]=k;
        if(k)
            k--;
    }
    return lcp;
}
int main()
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
    string s1, s2;

    cin>>s1>>s2;


        string s=s1+"#"+s2;

        auto p=suffix_arary_construction(s);
        auto lcp2=lcp_construction(s,p);
        int mx=0;

        int b1=s1.length();
        int kk=p.size();
        for(int i=0;i<kk-1;i++)
        {
                if((p[i]<b1&& p[i+1]>b1)||(p[i]>b1 && p[i+1]<b1))

                mx=max(mx, lcp2[i]);

        }
        cout<<mx;




}
