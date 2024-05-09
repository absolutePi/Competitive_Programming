#include <bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;
const int N = 21;
int dp[1<<20][21];
vector<int> adj[21];

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[b].push_back(a);
    }
    dp[1][1]=1;
    for(int s=2;s<(1<<n);s++){
        if(s&(1<<(n-1))&&s!=(1<<n)-1){continue;}
        for(int c=1;c<=n;c++){
            if(s&(1<<(c-1))){
                for(auto &i : adj[c]){
                    if(s&&(1<<(i-1))){
                        dp[s][c]+=dp[s^(1<<(c-1))][i];
                        dp[s][c]%=MOD;
                    }
                }
            }
        }
    }
    cout << dp[(1<<n)-1][n]%MOD;
}