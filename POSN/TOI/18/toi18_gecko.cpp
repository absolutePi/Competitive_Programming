#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
const int N = 2e4+5;
const int INF=2e9;
int n,m,k,st,a[N],par[N],dist[N];
vector<pair<int,int>> adj[N];
priority_queue<pii,vector<pii>,greater<pii>> pq;
bool vis[N];
vector<int> vec[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k >> st;
    for(int i=0;i<n;i++){
        dist[i]=INF;
    }
    for(int i=0;i<k;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }
    dist[st]=0;
    pq.push({dist[st],st});//dist node
    par[st]=-1;
    while(!pq.empty()){
        int node=pq.top().second;
        pq.pop();
        if(vis[node])continue;
        for(auto nx : adj[node]){
            int next_node=nx.second;
            int weight=nx.first;
            if(dist[next_node]>dist[node]+weight){
                dist[next_node]=dist[node]+weight;
                par[next_node]=node;
                pq.push({dist[next_node],next_node});
            }
        }
    }
    for(int i=0;i<k;i++){
        cout << dist[a[i]] << ' ';
    }
    cout << '\n';
    for(int i=0;i<n;i++){
        vis[i]=false;
    }
    for(int i=0;i<k;i++){
        int curr=a[i];
        while(curr!=st&&!vis[curr]){
            vis[curr]=true;
            vec[curr].push_back(par[curr]);
            vec[par[curr]].push_back(curr);
            curr=par[curr];
        }
    }
    stack<pii> s;
    vector<pii> ans;
    s.push({-1,st});
    while(!s.empty()){
        int par=s.top().first;
        int node=s.top().second;
        s.pop();
        for(auto i : vec[node]){
            if(i==par)continue;
            s.push({node,i});
            ans.push_back({min(i,node),max(i,node)});
        }
    }
    reverse(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for(auto i : ans){
        cout << i.first << ' ' << i.second << '\n';
    }
}