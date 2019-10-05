#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define PI 3.1415926535897932384626433832795028841971693993751058209749
using namespace std;
    
typedef long long ll;
typedef long double ld;
#define READ(a) int a; cin >> a;
#define READARR(a, n) int a[(n) + 1] = {}; FOR(i, 1, (n)) {cin >> a[i];}
#define READMAT(a, n, m) int a[n + 1][m + 1] = {}; FOR(i, 1, n) {FOR(j, 1, m) cin >> a[i][j];}
#define pb(x) push_back(x)
#define fi first
#define se second
#define vi vector <int>
#define pi pair <int, int>
#define vpi vector <pi>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define all(X) X.begin(),X.end()
const ll inf = 1e18;
const ll mod = 1e9 + 7;

//#warning correct the MAXN


vector<int> prefix_function(string k)
{
    int n=k.size();
    vector<int> p(n);
    for(int i=1;i<n;i++)
    {
        int j=p[i-1];
        while(j>0 && k[i]!=k[j])
            j=p[j-1];
  
        if(k[i]==k[j])
            j++;
        p[i]=j;
    }
    return p;
}
signed main()
{
        ios::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
#ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
  //  freopen("ERROR.txt", "w", stderr);

#endif
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string b;
        cin>>b;
        int sz=b.size();
        s=b+"#"+s;
        auto pe=prefix_function(s);
        vector<int> ans;
        for(int i=sz;i<s.size();i++)
            if(pe[i]==sz)
                ans.pb(i-2*sz);
        if(ans.size())
        {
        cout<<ans.size()<<"\n";
        for(auto i:ans)
        cout<<i+1<<" "; 
        cout<<"\n";
        }
        else
        {
            cout<<"Not Found"<<"\n";
        }
        cout<<"\n";
        
    }  
}
