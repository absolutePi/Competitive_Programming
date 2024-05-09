#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int in_degree[N];
int n,m;
vector<int> adj[N];
vector<int> backedge[N];
vector<int> dist(N,-1);
vector<int> par(N,-1);

void topo(){
    queue<int> q;
    for(int i=0;i<n;i++){
        if(in_degree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto i : adj[curr]){
            in_degree[i]--;
            if(in_degree[i]==0){
                q.push(i);
            }
        }
        int mx=-999999999;
        int mx_node=-1;
        for(auto i : backedge[curr]){
            if(mx<dist[i]+1){
                mx=dist[i]+1;
                mx_node = i;
            }
        }
        dist[curr]=mx;
        if(curr==0){dist[curr]=1;}
        par[curr]=mx_node;
    }
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        in_degree[b]++;
        backedge[b].push_back(a);
    }
    topo();
    stack<int> ans;
    int temp=n-1;
    bool contain0=false;
    if(temp==0){contain0=true;}
    while(temp!=-1&&dist[temp]>=0){
        ans.push(temp);
        temp=par[temp];
        if(temp==0){
            contain0=true;
        }
    }
    if(contain0){
        cout << dist[n-1] << '\n';
        while(!ans.empty()){
            cout << ans.top()+1;
            ans.pop();
            if(!ans.empty()){cout << ' ';}
        }
        cout << '\n';
    }
    else{
        cout << "IMPOSSIBLE";
    }
}