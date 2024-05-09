#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;
vector<vector<int>> adj(N);
vector<bool> visited(N);
vector<int> subordinates(N);

int dfs(int node){
    visited[node]=true;
    int cur_sub=adj[node].size();
    for(auto i : adj[node]){
        if(!visited[i]){
            cur_sub+=dfs(i);
        }
    }
    subordinates[node]=cur_sub;
    return cur_sub;
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int a;
        cin >> a;
        adj[--a].push_back(i);
    }
    dfs(0);
    for(int i=0;i<n;i++){
        cout << subordinates[i] << ' ';
    }
    // cout << endl;
    // for(int i=0;i<n;i++){
    //     for(auto j : adj[i]){
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }
}