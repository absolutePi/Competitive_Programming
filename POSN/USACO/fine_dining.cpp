#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll INF = 1e10;
const ll N = 5e4+5;
vector<ll> adj[N];
map<pair<ll,ll>,ll> weight;


void dijkstras(ll start,vector<ll> &dist){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,start});
    vector<bool> vis(N);
    while(!pq.empty()){
        ll d=pq.top().first;
        ll node=pq.top().second;
        pq.pop();
        if(vis[node]){continue;}
        vis[node]=true;
        for(auto u : adj[node]){
            if(weight[{u,node}]+d<dist[u]){
                dist[u]=weight[{u,node}]+d;
                pq.push({dist[u],u});
            }
        }
    }
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("dining.in","r",stdin);
    freopen("dining.out","w",stdout);
    ll n,m,k;
    cin >> n >> m >> k;
    vector<pair<ll,ll>> bales(k);
    for(ll i=0;i<m;i++){
        ll a,b,w;
        cin >> a >> b >> w;
        adj[--b].push_back(--a);
        adj[a].push_back(b);
        weight[{a,b}]=w;
        weight[{b,a}]=w;
    }
    for(ll i=0;i<k;i++){
        ll a,y;
        cin >> a >> y;
        bales[i]={--a,y};
    }
    vector<ll> dist(n,INF);
    dist[n-1]=0;
    dijkstras(n-1,dist);
    vector<ll> ndist(n+1,INF);
    ndist[n]=0;
    for(ll i=0;i<k;i++){
        adj[n].push_back(bales[i].first);
        weight[{n,bales[i].first}]=weight[{bales[i].first,n}]=dist[bales[i].first]-bales[i].second;
    }
    dijkstras(n,ndist);
    for(ll i=0;i<n-1;i++){
        if(ndist[i]<=dist[i]){
            cout << 1 << '\n';
        }
        else{
            cout << 0 << '\n';
        }
    }
}

