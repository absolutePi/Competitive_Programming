#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 105;
vector<pair<int,int>> adj[N][N];
int vis[N][N];

signed main(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin >> c;
            if(c=='B'){
                adj[i][j].push_back({i+1,j});
                adj[i][j].push_back({i,j+1});
                adj[i+1][j].push_back({i,j});
                adj[i][j+1].push_back({i,j});
            }
            else if(c=='R'){
                adj[i][j].push_back({i,j+1});
                adj[i][j+1].push_back({i,j});
            }
            else if(c=='D'){
                adj[i][j].push_back({i+1,j});
                adj[i+1][j].push_back({i,j});
            }
        }
    }
    queue<tuple<int,int,int,int,int>> q;
    q.push({1,1,1,-1,-1});//dist x y parx pary
    while(!q.empty()){
        int dist,x,y,parx,pary;
        tie(dist,x,y,parx,pary)=q.front();
        q.pop();
        vis[x][y]++;
        if(vis[x][y]==2){
            cout << dist << '\n' << x << ' ' << y << '\n';
            return 0;
        }
        for(auto i : adj[x][y]){
            if(i.first!=parx||i.second!=pary){
                q.push({dist+1,i.first,i.second,x,y});
            }
        }
    }
}