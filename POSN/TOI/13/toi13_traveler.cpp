#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+5;
const int INF=1e9+7;
int n,m,start,target,budget;
vector<pair<int,int>> adj[N];
int s_dist[N],t_dist[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    cin >> start >> target >> budget;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    for(int i=0;i<n;i++){
        s_dist[i]=INF;
        t_dist[i]=INF;
    }
    queue<int> q;
    s_dist[start]=0;
    q.push(start);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto u : adj[curr]){
            int nx=u.first;
            int weight=u.second;
            if(s_dist[curr]+weight<s_dist[nx]){
                s_dist[nx]=s_dist[curr]+weight;
                q.push(nx);
            }
        }
    }
    q.push(target);
    t_dist[target]=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto u : adj[curr]){
            int nx=u.first;
            int weight=u.second;
            if(t_dist[curr]+weight<t_dist[nx]){
                t_dist[nx]=t_dist[curr]+weight;
                q.push(nx);
            }
        }
    }
    vector<pair<int,int>> end_node;//{dist from the end node,end node}
    for(int i=0;i<n;i++){
        end_node.push_back({t_dist[i],i});
    }
    sort(end_node.begin(),end_node.end());
    for(auto i : end_node){
        int ind=i.second;
        if(s_dist[ind]<=budget){
            cout << ind << ' ' << s_dist[ind] << ' ' << t_dist[ind];
            return 0;
        }
    }
}