#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
vector<int> adj[N];
bool vis[N];

bool dfs(int node){
    // cout << node << '\n';
    bool check=true;
    vis[node]=true;
    for(auto nx : adj[node]){
        if(vis[nx]){
            return false;
        }
        else{
            check&=dfs(nx);
        }
    }
    return check;
}

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int num;
        cin >> num;
        for(int j=0;j<num;j++){
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)vis[j]=false;
        if(dfs(i)){
            cout << "NO";
        }
        else cout << "YES";
        cout << '\n';
    }
    // if(dfs(2))cout << "NO";
    // else cout << "YES";
}