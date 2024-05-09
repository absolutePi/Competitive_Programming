#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
vector<int> adj[N];
int dp[N];

int solve(int x){
    if(dp[x])return dp[x];
    for(auto i : adj[x]){
        dp[x]=max(dp[x],solve(i)+1);
    }
    return dp[x];
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        solve(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    cout << ans << '\n';
}