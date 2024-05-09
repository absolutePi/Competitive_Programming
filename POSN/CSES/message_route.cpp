#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> dist(n+1,INT_MAX),parent(n+1);
    queue<int> q;
    q.push(1);
    dist[1]=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto i : adj[curr]){
            if(dist[i]==INT_MAX){
                dist[i]=dist[curr]+1;
                parent[i]=curr;
                q.push(i);
            }
        }
    }
    if(dist[n]==INT_MAX){
        cout << "IMPOSSIBLE";
    }
    else{
        cout << dist[n]+1 << '\n';
        vector<int> ans{n};
        while(ans.back()!=1){
            ans.push_back(parent[ans.back()]);
        }
        reverse(ans.begin(),ans.end());
        for(auto i : ans){cout << i << ' ';}
    }
}