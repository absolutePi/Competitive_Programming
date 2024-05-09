#include <bits/stdc++.h>

using namespace std;
const int N =2e5+1;

vector<vector<int>> adj;
vector<int> dist;
int n,m;

void bfs(int node){
    dist=vector<int>(n,-1);
    dist[node]=0;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int curr_node=q.front();
        q.pop();
        for(auto i : adj[curr_node]){
            if(dist[i]==-1){
                dist[i]=dist[curr_node]+1;
                q.push(i);
            }
        }
    }
} 

void solve(){
    cin >> n >> m;
    adj=vector<vector<int>>(n);
    vector<int> odd,even;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    bfs(0);
    for(int i=0;i<n;i++){
        if(dist[i]%2){
            odd.push_back(i);
        }
        else{
            even.push_back(i);
        }
    }
    if(odd.size()<even.size()){
        cout << odd.size() << endl;
        for(auto i : odd){
            cout << i+1 << ' ';
        }
    }
    else{
        cout << even.size() << endl;
        for(auto i : even){
            cout << i+1 << ' ';
        }
    }
    cout << endl;
    return;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
}