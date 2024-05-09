#include <bits/stdc++.h>

using namespace std;

const int N =1e5+1;
vector<vector<int>> adj1(N),adj2(N);
bool vis[N];

void dfs1(int node){
    if(vis[node]){return;}
    vis[node]=true;
    for(auto i : adj1[node]){
        dfs1(i);
    }
    return;
}

void dfs2(int node){
    if(vis[node]){return;}
    vis[node]=true;
    for(auto i : adj2[node]){
        dfs2(i);
    }
    return;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        adj1[a].push_back(b);
        adj2[b].push_back(a);
    }
    dfs1(0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            cout << "NO" << endl;
            cout << "1" << ' ' << i+1;
            return 0;
        }
    }
    fill(vis,vis+n,false);
    dfs2(0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            cout << "NO" << endl;
            cout << i+1 << ' ' << 1;
            return 0;
        }
    }
    cout << "YES" << endl;
}