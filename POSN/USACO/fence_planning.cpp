#include <bits/stdc++.h>

using namespace std;

struct Cow{
    int x,y;
    vector<int> adj;
    bool visited;
};

vector<Cow> cows;
vector<int> curr_net;

void dfs(int node){
    cows[node].visited=true;
    curr_net.push_back(node);
    for(auto i : cows[node].adj){
        if(!cows[i].visited){
            dfs(i);
        }
    }
    return;
}

int main(){
    freopen("fenceplan.in","r",stdin);
    freopen("fenceplan.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,m;
    cin >> n >> m;
    cows.resize(n);
    for(auto &c : cows){
        cin >> c.x >> c.y;
        c.visited=false;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        cows[a-1].adj.push_back(b-1);
        cows[b-1].adj.push_back(a-1);
    }
    vector<vector<int>> networks;
    for(int i=0;i<n;i++){
        if(!cows[i].visited){
            curr_net.clear();
            dfs(i);
            networks.push_back(curr_net);}
    }
    int ans=INT_MAX;
    for(auto i : networks){
        int mn_x=INT_MAX;
        int mn_y=INT_MAX;
        int mx_x=0;
        int mx_y=0;
        for(auto j : i){
            mn_x=min(mn_x,cows[j].x);
            mn_y=min(mn_y,cows[j].y);
            mx_x=max(mx_x,cows[j].x);
            mx_y=max(mx_y,cows[j].y);
        }
        ans=min(ans,2*(mx_x-mn_x)+2*(mx_y-mn_y));
    }
    cout << ans;
}