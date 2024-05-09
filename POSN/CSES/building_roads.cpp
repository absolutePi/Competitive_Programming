#include <bits/stdc++.h>

using namespace std;

int n,m;
bool visited[100005];
vector<int> adj[100005];


void dfs(int node){
    if(visited[node])return;
    visited[node]=true;
    for(auto i : adj[node]){
        dfs(i);
    }
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    vector<pair<int,int>> rtb;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            adj[1].push_back(i);
            adj[i].push_back(1);
            rtb.push_back({1,i});
            dfs(i);
        }
    }
    cout << rtb.size() << endl;
    for(auto i : rtb){
        cout << i.first << ' ' << i.second << endl;
    }
}