#include <bits/stdc++.h>

using namespace std;

#define tup tuple<int,int,int>
const int N = 2005;
vector<pair<int,int>> adj[N];
vector<pair<int,int>> ways[N];//dist steps

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,s,e,m;
    cin >> n >> s >> e >> m;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
    }
    priority_queue<tup,vector<tup>,greater<tup>> q;
    q.push({0,0,s});//dist steps node
    while(!q.empty()){
        int dist=get<0>(q.top());
        int steps=get<1>(q.top());
        int node=get<2>(q.top());
        q.pop();
        for(auto u : adj[node]){
            int nx=u.first;
            int weight=u.second;
            bool valid=true;
            for(auto v : ways[nx]){
                if(dist+weight>=v.first&&steps+1>v.second){valid=false;break;}
            }
            if(valid){
                q.push({dist+weight,steps+1,nx});
                ways[nx].push_back({dist+weight,steps+1});
            }
        }
    }
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int level;
        cin >> level;
        int ans=INT_MAX;
        for(auto j : ways[e]){
            ans=min(ans,j.first+(j.second-1)*level);
        }
        cout << ans << ' ';
    }
}