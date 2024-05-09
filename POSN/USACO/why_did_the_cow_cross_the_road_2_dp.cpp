#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("nocross.in","r",stdin);
    freopen("nocross.out","w",stdout);
    int n;
    cin >> n;
    vector<int> f(n+1),s(n+1);
    for(int i=1;i<=n;i++){
        cin >> f[i];
    }
    for(int i=1;i<=n;i++){
        cin >> s[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=max({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]+(abs(f[i]-s[j])<=4)});
        }
    }
    cout << dp[n][n];
}