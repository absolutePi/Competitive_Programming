#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

struct Edge{
    int v;
    int c;
    int f;
};
vector<Edge> adj[N];
int ans[N];

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("pump.in","r",stdin);
    freopen("pump.out","w",stdout);
    int n,m;    
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,c,f;
        cin >> a >> b >> c >> f;
        adj[--a].push_back({--b,c,f});
        adj[b].push_back({a,c,f});
    }
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> q;
    int INF = 1e8;
    q.push({0,INF,0});//dist flowrate node
    while(!q.empty()){
        tuple<int,int,int> curr=q.top();
        q.pop();
        int dist = get<0>(curr);
        int flowrate = get<1>(curr);
        int node = get<2>(curr);
        for(auto u : adj[node]){
            int f=min(flowrate,u.f);
            int d=dist+u.c;
            int b=u.v;
            if(ans[b]<(f*1e6/d)){
                ans[b]=f*1e6/d;
                q.push({d,f,b});
            }
        }
    }
    cout << ans[n-1] << '\n';
}