#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
const int N = 1e5+5;
vector<pii> adj[N];
int dist[N];
bool vis[N];

int main(){
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }
    for(int i=1;i<=n;i++)dist[i]=2e9;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    dist[1]=0;
    q.push({0,1});//dist node
    int ans=INT_MIN;
    while(!q.empty()){
        int curr_dist,node;
        tie(curr_dist,node)=q.top();q.pop();
        if(vis[node])continue;
        vis[node]=true;
        ans=max(ans,curr_dist);
        for(auto i : adj[node]){
            if(dist[node]+i.first<dist[i.second]){
                q.push({dist[i.second]=dist[node]+i.first,i.second});
            }
        }
    }
    cout << ans << '\n';
}