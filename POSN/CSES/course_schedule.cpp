#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
vector<int> adj[N];
bool vis[N];
int n,m;
vector<int> ans;

void dfs(int node){
    vis[node]=true;
    for(auto i : adj[node]){
        if(!vis[i]){
            dfs(i);
        }
    }
    ans.push_back(node);
    return;
}

void topo(){
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    reverse(ans.begin(),ans.end());
    return;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].push_back(--b);
    }
    topo();
    vector<int> ind(n);
    for(int i=0;i<n;i++){
        ind[ans[i]]=i;
    }
    for(int i=0;i<n;i++){
        for(auto j : adj[i]){
            if(ind[j]<=ind[i]){
                cout << "IMPOSSIBLE" << '\n';
                return 0;
            }
        }
    }
    for(auto i : ans){
        cout << i+1 << ' ';
    }
}