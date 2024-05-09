#include <bits/stdc++.h>

using namespace std;

const int MAX_DAYS = 1000;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("time.in","r",stdin);
    freopen("time.out","w",stdout);
    int n,m,c;
    cin >> n >> m >> c;
    vector<int> cost(n);
    for(auto &i : cost){cin >> i;}
    vector<vector<int>> adj(n);//cities are 0-indexed
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[--a].push_back(--b);
    }
    vector<vector<int>> dp(MAX_DAYS+1,vector<int>(n,-1));//dp[day][city]=max_money
    dp[0][0]=0;
    int ans=0;
    for(int day=0;day<MAX_DAYS;day++){
        for(int city=0;city<n;city++){
            if(dp[day][city]!=-1){
                for(auto next : adj[city]){
                    dp[day+1][next]=max(dp[day+1][next],dp[day][city]+cost[city]);
                }
            }
        }
        ans = max(ans,dp[day][0]-(c*day*day));
    }
    cout << ans << '\n';
}