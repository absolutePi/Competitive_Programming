#include <bits/stdc++.h>

using namespace std;
#define pii pair<int,int>

const int N = 2505;

int n,m;
vector<pii> edge;
vector<vector<int>> adj;
bool vis[N];
int dist[N];

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> m;
    adj.resize(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
        edge.push_back({a,b});
    }
    int ans=INT_MAX;
    for(auto i : edge){
        memset(vis,false,sizeof(vis));
        memset(dist,0,sizeof(dist));
        queue<pii> q;
        q.push(i);
        while(!q.empty()){
            int curr=q.front().first;
            int par=q.front().second;
            q.pop();
            // int curr,par;
            // tie(curr,par)=q.front();q.pop();
            // auto [curr,par] = q.front();
            // q.pop();
            if(vis[curr]){continue;}
            vis[curr]=true;
            if(curr==i.second){break;}
            for(auto j : adj[curr]){
                if(j!=par){
                    dist[j]=dist[curr]+1;
                    q.push({j,curr});
                }
            }
        }
        if(vis[i.second]){
            ans=min(ans,dist[i.second]+1);
        }
    }   
    if(ans==INT_MAX){cout << "-1" << '\n';}
    else{
        cout << ans << '\n';
    }
}   