#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll N =1e5+1;

vector<vector<ll>> adj;
bool visited[N];
vector<ll> colored,uncolored;

void dfs(ll node,ll curr_color){
    if(!visited[node]){
        visited[node]=true;
        if(curr_color==0){
            colored.push_back(node);
        }
        else if(curr_color==1){
            uncolored.push_back(node);
        }
        ll next_color= curr_color==0 ? 1 : 0;
        for(auto i : adj[node]){
            if(!visited[i]){
                dfs(i,next_color);
            }
        }
    }
    return;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll n;
    cin >> n;
    adj=vector<vector<ll>>(n);
    for(ll i=0;i<n-1;i++){
        ll a,b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    for(ll i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,0);
        }
    }
    cout << (ll)colored.size()*(ll)uncolored.size()-(n-1);
}