#include <bits/stdc++.h>

using namespace std;

int n[2],m[2];
static const int N = 1005;
static const int M = 2005;
vector<int> adj[2][N];
vector<int> back[2][N];
bitset<M> dp[2][N];

void solve(int x){
    int in_degree[N]={};
    for(int i=0;i<m[x];i++){
        int a,b;
        cin >> a >> b;
        adj[x][a].push_back(b);
        back[x][b].push_back(a);
        in_degree[b]++;
    }
    queue<int> q;
    for(int i=0;i<=n[x];i++){
        if(in_degree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto i : adj[x][curr]){
            in_degree[i]--;
            if(in_degree[i]==0){
                q.push(i);
            }
        }
        if(back[x][curr].empty()){
            dp[x][curr][0]=1;
        }
        for(auto i : back[x][curr]){
            dp[x][curr]|=dp[x][i]<<1;
        }
    }
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n[0] >> n[1] >> m[0] >> m[1];
    solve(0);
    solve(1);
    bitset<M> ans;
    for(int i=0;i<=M;i++){
        if(dp[0][n[0]][i]){
            ans|=dp[1][n[1]]<<i;
        }
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int a;
        cin >> a;
        if(ans[a]){
            cout << "Yes" << '\n';
        }
        else{
            cout << "No" << '\n';
        }
    }
}