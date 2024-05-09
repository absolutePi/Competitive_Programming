#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> adj;

int dfs(int node,int parent){
    int ans=0;
    //including itself and neighbors, excluding parent
    int cows = adj[node].size();
    if(parent==-1){
        cows++;//no parent to exclude
    }
    int curr_cows=1;
    while(curr_cows<cows){
        ans++;
        curr_cows*=2;
    }
    for(auto i : adj[node]){
        if(i!=parent){
            ans+=dfs(i,node)+1;
        }
    }
    return ans;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n;
    adj = vector<vector<int>>(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    cout << dfs(0,-1) << endl;
}