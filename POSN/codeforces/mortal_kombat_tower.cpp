#include <bits/stdc++.h>

using namespace std;

const int INF = 2e5+5;

void solve(){
    int n;
    cin >> n;
    vector<int> boss(n);
    for(auto &i : boss){cin >> i;}
    vector<vector<int>> dp(n+1,vector<int>(2,INF));//1 = friend
    dp[0][1]=0;
    for(int i=0;i<n;i++){
        dp[i+1][0]=min(dp[i+1][0],dp[i][1]+boss[i]);
        dp[i+1][1]=min(dp[i+1][1],dp[i][0]);
        if(i+2<=n){
            dp[i+2][0]=min(dp[i+2][0],dp[i][1]+boss[i]+boss[i+1]);
            dp[i+2][1]=min(dp[i+2][1],dp[i][0]);
        }
    }
    cout << min(dp[n][0],dp[n][1]) << '\n';
    return;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
}