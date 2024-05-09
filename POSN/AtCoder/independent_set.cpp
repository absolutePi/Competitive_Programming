#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1e9+7;
const int N = 1e5+5;
vector<int> adj[N];
int dp[N][2];

int recur(int color,int node,int par){
    if(dp[node][color])return dp[node][color];
    int curr=1;
    for(auto nx : adj[node]){
        if(nx!=par){
            if(color){
                curr=(curr*recur(0,nx,node))%MOD;
            }
            else{
                curr=(curr*(recur(0,nx,node)+recur(1,nx,node)))%MOD;
            }
        }
    }
    return dp[node][color]=curr;
}

signed main(){
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int ans=(recur(0,1,-1)+recur(1,1,-1))%MOD;
    cout << ans;
}