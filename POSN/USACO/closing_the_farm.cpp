#include <bits/stdc++.h>

using namespace std;

vector<int> adj[5000];
bool visited[5000];
bool closed[5000];
int nodes_visited=0;
vector<int> order;

void dfs(int node){
    if(visited[node]||closed[node]){return;}
    visited[node]=true;
    nodes_visited++;
    for(auto i : adj[node]){
        dfs(i);
    }
}

int main(){
    freopen("closing.in","r",stdin);
    freopen("closing.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        order.push_back(a);
    }
    dfs(1);
    if(nodes_visited==n){
        cout << "YES";
    }
    else cout << "NO";
    cout << endl;
    for(int i=0;i<n-1;i++){
        nodes_visited=0;
        fill(visited,visited+5000,false);
        closed[order[i]]=true;
        dfs(order[n-1]);
        if(nodes_visited==n-i-1){
            cout << "YES";
        }
        else cout << "NO";
        cout << endl;
    }
}