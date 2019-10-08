#include<bits/stdc++.h>
#define int long long int
#define loop(i, a, b) for(int i = a;i <= b; ++i)
#define rloop(i, a, b) for(int i = a;i >= b; --i)
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define p (int)(1e9 + 7) 
using namespace std;
 
signed main(){
 
    // #ifndef ONLINE_JUDGE
    // //for getting input from input.txt
    // freopen("input.txt", "r", stdin);
    // // for writing output to output.txt
    // freopen("output.txt", "w", stdout);
    // #endif
 
    fast;
    int n;cin>>n;
    int dp[n+1][n+1] = {};
    string m[n];
    loop(i,1,n)
        cin>>m[i-1];
    dp[1][0] = 1;
    loop(i,1,n)
        loop(j,1,n)
            if(m[i-1][j-1] != '*')
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%p; 
 
    cout<<dp[n][n]<<endl;
    return 0;
        
}
