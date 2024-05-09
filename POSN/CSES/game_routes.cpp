#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll N = 1e5+5;
const ll MOD = 1e9+7;
vector<int> adj[N];
ll n,m;
ll in_degree[N];
ll dist[N];

void topo(){
    dist[0]=1;
    queue<ll> q;
    for(ll i=0;i<n;i++){
        if(in_degree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        ll curr=q.front();
        q.pop();
        for(auto i : adj[curr]){
            dist[i]+=dist[curr]%MOD;
            in_degree[i]--;
            if(in_degree[i]==0){
                q.push(i);
            }
        }
    }
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> m;
    for(ll i=0;i<m;i++){
        ll a,b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        in_degree[b]++;
    }
    topo();
    cout << dist[n-1]%MOD << '\n';
}