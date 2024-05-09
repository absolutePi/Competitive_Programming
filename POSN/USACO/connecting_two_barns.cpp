#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int N =1e5+1;
vector<int> adj[N];// neighbors
vector<int> comps[N];//creating groups, each groups has dif father
int comp[N];//father of the ith component

void dfs(int node,int father){
    if(comp[node]!=-1){return;}
    comp[node]=father;
    for(auto i : adj[node]){
        dfs(i,father);
    }
}

ll cost(int a,int b){
    int dist = N;
    for(auto u : comps[a]){
        int i = lower_bound(comps[b].begin(),comps[b].end(),u)-comps[b].begin();
        if(i>0){
            dist=min(dist,abs(comps[b][i-1]-u));
        }
        if(i<comps[b].size()){
            dist=min(dist,abs(comps[b][i]-u));
        }
    }
    return (ll)dist*dist;
}

void solve(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        adj[i].clear();
        comps[i].clear();
        comp[i]=-1;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    int curr_father=-1;
    for(int i=0;i<n;i++){
        if(comp[i]==-1){
            dfs(i,++curr_father);
        }
    }
    //now all the component will have their father filled in arr "comp"
    for(int i=0;i<n;i++){
        comps[comp[i]].push_back(i);
    }
    ll res=cost(comp[0],comp[n-1]);
    for(int i=1;i<curr_father;i++){
        res=min(res,cost(i,comp[0])+cost(i,comp[n-1]));
    }
    cout << res << endl;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
}