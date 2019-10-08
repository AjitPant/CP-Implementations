#include<bits/stdc++.h>
#define int long long int
#define loop(i, a, b) for(int i = a;i <= b; ++i)
using namespace std;
 
const int INF = 1e17;
const int p = 1e9+7;
 
vector<int>  used;
list<int> topo;
vector<vector<int>> adj, inEdges;
 
void toposort(int v){
    used[v] = 1;
    for(int child:adj[v]){
        if(!used[child]){
            toposort(child);
        }
    }
    topo.push_front(v);
}
    
signed main(){
 
    int n, m;
    cin>>n>>m;
    adj.resize(n+1);
    inEdges.resize(n+1);
    used.resize(n+1, 0);
    loop(i,0,m-1){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        inEdges[y].push_back(x);
    }
    toposort(1);
    int dp[n+1] = {0};
    dp[1] = 1;  
    for(int i:topo){
        for(int child : inEdges[i]){
            dp[i] += dp[child];
            dp[i] %= p;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
