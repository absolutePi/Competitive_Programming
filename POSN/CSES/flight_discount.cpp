#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll INF = 1e18;
ll n,m;

vector<ll> ans(ll start,vector<vector<pair<ll,ll>>> neighbor){
    vector<ll> dist(n,INF);
    vector<bool> vis(n);
    dist[start]=0;
    priority_queue<pair<ll,ll>> q;
    q.push({0,start});
    while(!q.empty()){
        ll a=q.top().second;
        q.pop();
        if(vis[a]){continue;}
        vis[a]=true;
        for(auto u : neighbor[a]){
            ll b=u.second;
            ll w=u.first;
            if(dist[a]+w<dist[b]){
                dist[b]=dist[a]+w;
                q.push({-dist[b],b});
            }
        }
    }
    return dist;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> adj(n),radj(n);//weight and node
    for(ll i=0;i<m;i++){
        ll a,b,w;
        cin >> a >> b >> w;
        adj[--a].push_back({w,--b});
        radj[b].push_back({w,a});
    }
    vector<ll> prefix = ans(0,adj);
    vector<ll> suffix = ans(n-1,radj);
    ll min_cost=INF;
    for(int c=0;c<n;c++){
        for(auto u : adj[c]){
            if(prefix[c]==INF || suffix[u.second]==INF){continue;}
            min_cost=min(min_cost,prefix[c]+(u.first/2)+suffix[u.second]);
        }
    }
    cout << min_cost << '\n';
}