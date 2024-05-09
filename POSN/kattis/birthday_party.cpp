#include <bits/stdc++.h>

using namespace std;

int n,m;
bool adj[105][105];
bool visited[105];

void dfs(int node){
    visited[node]=true;
    for(int to=0;to<n;to++){
        if(adj[node][to]&&!visited[to]){
            dfs(to);
        }
    }
    return;
}

void solve(){
    memset(adj,false,sizeof(adj));
    vector<pair<int,int>> edges;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a][b]=true;
        adj[b][a]=true;
        edges.push_back({a,b});
    }
    for(auto i :  edges){
        adj[i.first][i.second]=false;
        adj[i.second][i.first]=false;
        memset(visited,false,sizeof(visited));
        dfs(0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cout << "YES" << endl;
                return;
            }
        }
        adj[i.first][i.second]=true;
        adj[i.second][i.first]=true;
    }
    cout << "NO" << endl;
    return;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    while(cin >> n >> m && (n||m)){solve();}
}