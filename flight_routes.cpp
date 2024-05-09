#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll N = 1e5+5;
vector<pair<ll,ll>> adj[N];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
priority_queue<ll> best[N];
ll n,m,k;

void dijkstras(ll start){
    best[0].push(0);
    q.push({0,start});
    while(!q.empty()){
        ll d=q.top().first;
        ll node=q.top().second;
        q.pop();
        if(d>best[node].top()){continue;}
        for(auto u : adj[node]){
            ll dist=d+u.second;
            if(best[u.first].size()<k){
                best[u.first].push(dist);
                q.push({dist,u.first});
            }
            else if(dist<best[u.first].top()){
                best[u.first].pop();
                best[u.first].push(dist);
                q.push({dist,u.first});
            }
        }
    }
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> m >> k;
    for(ll i=0;i<m;i++){
        ll a,b,w;
        cin >> a >> b >> w;
        adj[--a].push_back({--b,w});
    }
    dijkstras(0);
    vector<ll> ans;
    while(!best[n-1].empty()){
        ans.push_back(best[n-1].top());
        best[n-1].pop();
    }
    reverse(ans.begin(),ans.end());
    for(auto i : ans){
        cout << i << ' ';
    }
}