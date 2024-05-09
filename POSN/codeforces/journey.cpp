#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+1;
vector<int> visited(N);
vector<vector<int>> adj(N);
double ans;

void dfs(int node,double curr_pos,int curr_dist){
    visited[node]=true;
    int poss_move=0;
    for(auto i : adj[node]){
        if(!visited[i]){
            poss_move++;
        }
    }
    if(!poss_move){
        ans+=curr_dist*curr_pos;
    }
    else{
        curr_pos/=poss_move;
        for(auto i : adj[node]){
            if(!visited[i]){
                dfs(i,curr_pos,curr_dist+1);
            }
        }
    }
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,1,0);
    cout << fixed << setprecision(10) << ans;
}