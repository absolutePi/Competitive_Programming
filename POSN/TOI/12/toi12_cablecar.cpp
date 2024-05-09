#include <bits/stdc++.h>

using namespace std;

const int N = 2505;
vector<pair<int,int>> adj[N];
int dist[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[--a].push_back({--b,w});
        adj[b].push_back({a,w});
    }
    int start,end,tourist;
    cin >> start >> end >> tourist;
    start--;end--;
    dist[start]=INT_MAX;
    priority_queue<pair<int,int>> q;
    q.push({dist[start],start});
    while(!q.empty()){
        int path_min=q.top().first;
        int node=q.top().second;
        q.pop();
        for(auto i : adj[node]){
            int curr_min=min(path_min,i.second);
            int next_node=i.first;
            if(curr_min>dist[next_node]){
                dist[next_node]=curr_min;
                q.push({dist[next_node],next_node});
            }
        }
    }
    int max_ride=dist[end]-1;//subtracting the guidance
    int ans=tourist/max_ride;
    if(tourist%max_ride)ans++;
    cout << ans << '\n';
}