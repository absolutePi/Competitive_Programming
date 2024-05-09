#include <bits/stdc++.h>

using namespace std;

const int MAX_LEVEL=10005;
const int N = 100005;

int n,k,t,steps,ans;
vector<int> node_level[MAX_LEVEL];
vector<int> adj[N];
int vis[N];

void dfs(int node){
    if(vis[node]==2||steps>t){return;}
    vis[node]=1;
    steps++;
    for(auto v : adj[node]){
        if(vis[v]==1){
            steps=INT_MAX;
            return;
        }
        dfs(v);
    }
    vis[node]=2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> t;
    for(int i=1;i<=n;i++){
        int level,neighbor;
        cin >> level >> neighbor;
        node_level[level].push_back(i);
        for(int j=0;j<neighbor;j++){
            int a;
            cin >> a;
            adj[i].push_back(a);
        }
    }
    for(int i=1;i<=k;i++){
        for(auto u : node_level[i]){
            if(!vis[u]){
                dfs(u);
            }
        }
        if(steps>t){
            break;
        }
        ans=i;
    }
    if(ans==0){
        cout << -1 << '\n';
        return 0;
    }
    cout << ans << '\n';
}