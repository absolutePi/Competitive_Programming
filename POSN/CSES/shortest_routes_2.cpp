#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll N = 505;
const ll INF = 1e18;
vector<vector<ll>> dist(N,vector<ll>(N,INF));

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll n,m,q;
    cin >> n >> m >> q;
    for(ll i=0;i<m;i++){
        ll a,b,w;
        cin >> a >> b >> w;
        dist[a][b]=min(dist[a][b],w);
        dist[b][a]=min(dist[b][a],w);
    }
    for(ll i=1;i<=n;i++){
        dist[i][i]=0;
    }
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    for(ll i=0;i<q;i++){
        ll a,b;
        cin >> a >> b;
        cout << (dist[a][b]==INF ? -1 : dist[a][b]) << '\n';
    }
}   