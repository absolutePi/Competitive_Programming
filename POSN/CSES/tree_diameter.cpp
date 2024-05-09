#include <bits/stdc++.h>

using namespace std;

int n;
int max_dist;
int farthest_node;
vector<vector<int>> adj;

void dfs(int node,int parent,int dept){
    for(auto i : adj[node]){
        if(i!=parent){
            dfs(i,node,dept+1);
        }
    }
    if(dept>max_dist){
        max_dist=dept;
        farthest_node=node;
    }
    return;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n;
    adj = vector<vector<int>>(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    dfs(0,-1,0);
    max_dist=0;
    dfs(farthest_node,-1,0);
    cout << max_dist << endl;
}