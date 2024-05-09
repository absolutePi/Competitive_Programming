#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("atlarge.in","r",stdin);
    freopen("atlarge.out","w",stdout);
    int n,k;
    cin >> n >> k;
    k--;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    queue<int> q;
    q.push(k);
    vector<int> distb(n,INT_MAX),distf(n,INT_MAX);
    distb[k]=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto i : adj[curr]){
            if(distb[curr]+1<distb[i]){
                distb[i]=distb[curr]+1;
                q.push(i);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(adj[i].size()==1){
            q.push(i);
            distf[i]=0;
        }
    }
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto i : adj[curr]){
            if(distf[curr]+1<distf[i]){
                distf[i]=distf[curr]+1;
                q.push(i);
            }
        }
    }
    q.push(k);
    vector<bool> vis(n);
    int ans=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        vis[curr]=true;
        if(distf[curr]<=distb[curr]){
            ans++;
            continue;
        }
        for(auto i : adj[curr]){
            if(!vis[i]){
                q.push(i);
            }
        }
    }
    cout << ans << '\n';
}