//Required Libraries

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


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
#define reset(X) memset(X, 0, sizeof(X))
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
const int K=256;
int strings_added=0;
struct Trie
{
    int next[K];
    int link;
    int ch;
    int p;
    int go[K];
    bool leaf=false;
    int next_leaf=-1;
    vector<int> string_part_of;
    Trie(int p=-1, char ch='$'):p(p), ch(ch)
    {
        fill_n(next, K, -1);
        link=-1;
        fill_n(go, K, -1);

    }
    

};
vector<Trie> t(1);
void add_string(string s)
{
    int v=0;
    for(auto ch:s)
    {
        int link=ch;
        if(t[v].next[link]==-1)
        {
            t[v].next[link]=t.size();
            t.emplace_back(v, ch);
        
        }
        v=t[v].next[link];
    }
    t[v].leaf=true;
    t[v].string_part_of.pb(strings_added);
    strings_added++;
}
int go(int v, char ch);
int get_link(int v)
{
    if(t[v].link==-1)
    {
        if(v==0 || t[v].p==0)
            return 0;
        t[v].link=go(get_link(t[v].p),t[v].ch);
    }
    return t[v].link;
}
int go(int v, char ch)
{
    int link=ch;
    if(t[v].go[link]==-1)
    {
        if(t[v].next[link]==-1)
        {
            t[v].go[link]=(v==0?0:go(get_link(v),ch ));
            
        }
        else t[v].go[link]=t[v].next[link];
    }
    return t[v].go[link];
}
int next_leaf(int v)
{
    if(v==0)
        return 0;
    if(t[v].next_leaf==-1)
    {
        
        int next_v=get_link(v);
        int next_leaf_a=next_leaf(next_v);
        if(t[next_v].leaf==true)
        {
            t[v].next_leaf=next_v;
            return t[v].next_leaf;
        }
        else
        {
            t[v].next_leaf=next_leaf_a;
        }
        
       
    }
    return t[v].next_leaf;
}
signed main()
{
    ios::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    #ifndef ONLINE_JUDGE
    freopen ("INPUT.txt", "r", stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    freopen ("ERROR.txt" , "w" , stderr);
    
    #endif
    //start from here
    int k;
    k=1;
    while(k--)

    {
        t.resize(0);
        t.resize(1);
        strings_added=0;
        string s;
        cin>>s;
        int q;
        cin>>q;
        int arr[q];
        reset(arr);
        while(q--)
        {
            string l;
            cin>>l;
            add_string(l);

        }
        int v=0;
        for(auto ch:s)
        {
            int c = ch;
            v = go(v, c);
            if(true)
            {
                if(t[v].leaf==true)
                {
                    for(auto kkk:t[v].string_part_of)
                        arr[kkk] = true;
                }
                int v_copy = v;
                while (v_copy != 0)
                {
                    v_copy = next_leaf(v_copy);
                    if (v_copy != 0)
                    {
                         for(auto kkk:t[v_copy].string_part_of)

                        arr[kkk] = true;
                    }
                }
            }
        }
        for(auto I:arr)
        {
            if(I==true)
                cout<<'Y'<<"\n";
            else
                cout<<'N'<<"\n";
        }
    }
    return 0;

}
