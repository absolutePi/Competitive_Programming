#include <bits/stdc++.h>

using namespace std;

int n,m;
string str;
const int N = 3e5+5;
vector<int> adj[N];
int in_degree[N];

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> m >> str;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        in_degree[b]++;
    }
    queue<int> q;
    vector<vector<int>> dp(n,vector<int>(26));
    for(int i=0;i<n;i++){
        if(in_degree[i]==0){
            q.push(i);
            dp[i][str[i]-'a']++;
        }
    }
    int sz=0;
    while(!q.empty()){
        int curr=q.front();
        sz++;
        q.pop();
        for(auto i : adj[curr]){
            for(int j=0;j<26;j++){
                if(j==(str[i]-'a')){
                    dp[i][j]=max(dp[i][j],dp[curr][j]+1);
                }
                else{
                    dp[i][j]=max(dp[i][j],dp[curr][j]);
                }
            }
            in_degree[i]--;
            if(in_degree[i]==0){
                q.push(i);
            }
        }
    }
    if(sz<n){
        cout << -1 << '\n';
        return 0;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            ans=max(ans,dp[i][j]);
        }
    }
    cout << ans << '\n';
}