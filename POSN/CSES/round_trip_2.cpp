#include <bits/stdc++.h>

using namespace std;

int n,m;
const int N = 1e5+5;
vector<int> adj[N];
bool vis[N],on_stack[N];
vector<int> ans;

bool dfs(int node){
    vis[node]=on_stack[node]=true;
    for(auto i : adj[node]){
        if(on_stack[i]){
            on_stack[i]=on_stack[node]=false;
            ans.push_back(node);
            return true;
        }
        else if(!vis[i]){
            if(dfs(i)){
                if(on_stack[node]){
                    on_stack[node]=false;
                    ans.push_back(node);
                    return true;
                }
                else{
                    ans.push_back(node);
                    return false;
                }
            }
            if(!ans.empty()){
                return false;
            }
        }
    }
    on_stack[node]=false;
    return false;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].push_back(--b);
    }
    for(int i=0;i<n&&ans.empty();i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    if(ans.empty()){
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }
    reverse(ans.begin(),ans.end());
    cout << ans.size()+1 << '\n';
    for(auto i : ans){
        cout << i+1 << ' ';
    }
    cout << ans[0]+1;
}