#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+5;
vector<int> adj[N];
bool vis[N];

int main(){
    int power,n,m;
    cin >> power >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    int ans=INT_MIN;
    queue<pair<int,int>> q;
    q.push({0,1});
    while(!q.empty()){
        int dist,floor;
        tie(dist,floor)=q.front();q.pop();
        if(vis[floor])continue;
        vis[floor]=true;
        if(dist<=power)ans=max(ans,floor);
        for(auto nx : adj[floor]){
            q.push({dist+1,nx});
        }
    }
    cout << ans << '\n';
}