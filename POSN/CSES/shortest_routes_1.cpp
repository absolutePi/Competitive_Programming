#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll INF = 1e18;
ll n,m;
const ll N = 1e5+5;
vector<pair<ll,ll>> adj[N];//weight and node
vector<ll> dist(N,INF);
bool vis[N];

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> m;
    for(ll i=0;i<m;i++){
        ll a,b,w;
        cin >> a >> b >> w;
        adj[--a].push_back({w,--b});
    }
    priority_queue<pair<ll,ll>> q;
    dist[0]=0;
    q.push({0,0});//weight and node
    while(!q.empty()){
        ll a=q.top().second;
        q.pop();
        if(vis[a]){continue;}
        vis[a]=true;
        for(auto u : adj[a]){
            ll w=u.first;
            ll b=u.second;
            if(dist[a]+w<dist[b]){
                dist[b]=dist[a]+w;
                q.push({-dist[b],b});
            }
        }
    }
    for(ll i=0;i<n;i++){
        cout << dist[i] << ' ';
    }
}