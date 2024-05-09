#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;
vector<int> counts(N);
vector<vector<int>> adj(N);

void dfs(int node,int parent){
    counts[node]=1;
    for(auto i : adj[node]){
        if(i==parent){continue;}
        dfs(i,node);
        counts[node]+=counts[i];
    }
    return;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    for(int i=2;i<=n;i++){
        int a;
        cin >> a;
        adj[a].push_back(i);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        cout << --counts[i] << ' ';
    }
}