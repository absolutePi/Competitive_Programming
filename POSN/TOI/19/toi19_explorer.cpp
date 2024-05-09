#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll N = 5e5+5;
const ll MOD=1e9+7;
vector<ll> adj[N];
bool vis[N];
ll fact[N];
ll ans=1;

void dfs(ll node){
    vis[node]=true;
    ll sz=0;
    for(auto nx : adj[node]){
        if(!vis[nx]){
            sz++;
        }
    }
    // cout << sz << "\n";
    // cout << ans << '\n';
    ans=(ans*fact[sz])%MOD;
    for(auto nx : adj[node]){
        if(!vis[nx]){
            dfs(nx);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    ll pre,start;
    for(ll i=0;i<2*n-1;i++){
        ll a;
        cin >> a;
        if(i){
            adj[pre].push_back(a);
        }
        else{
            start=a;
        }
        pre=a;
    }
    // cout << ans << '\n';
    fact[0]=1;
    fact[1]=1;
    for(ll i=2;i<N;i++){
        fact[i]=fact[i-1]*i;
        fact[i]%=MOD;
    }
    // for(ll i=0;i<4;i++){
    //     cout << fact[i] << '\n';
    // }
    // cout << ans << '\n';
    dfs(start);
    // cout << start << '\n';
    cout << ans << '\n';
}