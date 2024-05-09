#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll n,m;
const ll INF = 1e18;
const ll N = 1e5+5;
const ll MOD = 1e9+7;
vector<pair<ll,ll>> adj[N];
vector<ll> dist(N,INF);//minimum price
vector<ll> ways(N);
vector<ll> mxf(N);
vector<ll> mnf(N,INF);
bool vis[N];

void dijkstras(ll start){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0,start});//dist and node
    dist[start]=0;
    ways[start]=1;
    mnf[0]=0;
    while(!q.empty()){
        ll node=q.top().second;
        q.pop();
        if(vis[node]){continue;}
        vis[node]=true;
        for(auto u : adj[node]){
            if(dist[u.first]>dist[node]+u.second){
                dist[u.first]=dist[node]+u.second;
                ways[u.first]=ways[node];
                mxf[u.first]=mxf[node]+1;
                mnf[u.first]=mnf[node]+1;
                q.push({dist[u.first],u.first});
            }
            else if(dist[u.first]==dist[node]+u.second){
                ways[u.first]=(ways[u.first]+ways[node])%MOD;
                mxf[u.first]=max(mxf[u.first],mxf[node]+1);
                mnf[u.first]=min(mnf[u.first],mnf[node]+1);
            }
        }
    }
}
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> m;
    for(ll i=0;i<m;i++){
        ll a,b,w;
        cin >> a >> b >> w;
        adj[--a].push_back({--b,w});
    }
    dijkstras(0);
    cout << dist[n-1] << ' ' << ways[n-1] << ' ' << mnf[n-1] << ' ' << mxf[n-1] << '\n'; 
}