#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
vector<vector<pair<int,int>>> adj(N);
vector<bool> visited;
int n,q;
int limit;
int ans;

void solve(int node){
    visited[node]=true;
    for(auto i : adj[node]){
        if(i.second>=limit && !visited[i.first]){
            ans++;
            solve(i.first);
        }
    }
    return;
}

int main(){
    freopen("mootube.in","r",stdin);
    freopen("mootube.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n-1;i++){
        int a,b,w;
        cin >> a >> b >> w;
        a--;b--;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    for(int i=0;i<q;i++){
        int start;
        cin >> limit >> start;
        start--;
        visited=vector<bool>(n);
        ans=0;
        solve(start);
        cout << ans << endl;
    }
}