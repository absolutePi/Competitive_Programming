#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<vector<int>> dist;

void bfs(int node,int index){
    queue<int> q;
    q.push(node);
    dist[index][node]=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto i : adj[curr]){
            if(dist[index][i]==INT_MAX){
                dist[index][i]=dist[index][curr]+1;
                q.push(i);
            }
        }
    }
    return;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("piggyback.in","r",stdin);
    freopen("piggyback.out","w",stdout);
    int b,e,p,n,m;
    cin >> b >> e >> p >> n >> m;
    dist=vector<vector<int>>(4,vector<int>(n+1,INT_MAX));
    adj=vector<vector<int>>(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    bfs(0,0);
    bfs(1,1);
    bfs(n-1,2);
    int min_energy=INT_MAX;
    for(int i=0;i<n;i++){
        min_energy=min(min_energy,dist[0][i]*b+dist[1][i]*e+dist[2][i]*p);
    }
    cout << min_energy << '\n';
}