#include <bits/stdc++.h>

using namespace std;

int n,m,c;
const int N = 1e5+5;
int pos[N];
int in_degree[N];
vector<vector<pair<int,int>>> adj(N);

void solve(){
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
            pos[i.first]=max(pos[i.first],pos[curr]+i.second);
            in_degree[i.first]--;
            if(in_degree[i.first]==0){
                q.push(i.first);
            }
        }
    }
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("timeline.in","r",stdin);
    freopen("timeline.out","w",stdout);
    cin >> n >> m >> c;
    for(int i=0;i<n;i++){
        cin >> pos[i];
        pos[i]--;
    }
    for(int i=0;i<c;i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[--a].push_back({--b,w});
        in_degree[b]++;
    }
    solve();
    for(int i=0;i<n;i++){
        cout << pos[i]+1 << '\n';
    }
}