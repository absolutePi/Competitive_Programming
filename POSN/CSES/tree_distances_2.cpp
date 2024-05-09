#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll N = 2e5+1;
ll n;
vector<ll> adj[N];
ll sum;
ll subt_size[N];
ll ans[N];

void dfs(ll node,ll parent,ll dept){
    sum+=dept;
    for(auto i : adj[node]){
        if(i==parent){continue;}
        dfs(i,node,dept+1);
    }
    return;
}

ll dfs2(ll node,ll parent){
    subt_size[node]=1;
    for(auto i : adj[node]){
        if(i==parent){continue;}
        subt_size[node]+=dfs2(i,node);
    }
    return subt_size[node];
}   

void dfs3(ll node,ll parent,ll curr_sum){
    ans[node]=curr_sum;
    for(auto i : adj[node]){
        if(i==parent){continue;}
        dfs3(i,node,curr_sum+(n-2*subt_size[i]));
    }
    return;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n;
    for(ll i=0;i<n-1;i++){
        ll a,b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    dfs(0,-1,0);
    dfs2(0,-1);
    dfs3(0,-1,sum);
    for(ll i=0;i<n;i++){
        cout << ans[i] << ' ';
    }
}