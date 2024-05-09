#include <bits/stdc++.h>

using namespace std;

const int MAX_N=20;

vector<vector<int>> adj(MAX_N);
bool vis[MAX_N],cyclic[MAX_N];
int root;

void dfs(int node){
    vis[node]=true;
    if(node==root){
        cyclic[node]=true;
        return;
    }
    for(auto i : adj[node]){
        if(!vis[i]){
            dfs(i);
        }
    }
    return;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i=0;i<k;i++){
        int a,b,sa,sb;
        cin >> a >> b >> sa >> sb;
        if(sa>sb){
            adj[b-1].push_back(a-1);
        }
        else{
            adj[a-1].push_back(b-1);
        }
    }
    for(int i=0;i<n;i++){
        root=i;
        fill(vis,vis+MAX_N,false);
        for(auto j : adj[i]){
            dfs(j);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(cyclic[i])ans++;
    }
    cout << ans << endl;
}