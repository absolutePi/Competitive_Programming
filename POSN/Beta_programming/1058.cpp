#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int dp[4][N][N];//0 go left//1 go right//2 go down//3 go up
int grid[N][N];

void solve(){
    int n,m;
    cin >> n >> m;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        string str;
        cin >> str;
        for(int j=1;j<=m;j++){
            grid[i][j]=str[j-1]-'0';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(grid[i][j]==1){
                dp[0][i][j]=dp[0][i][j-1]+1;
                dp[2][i][j]=dp[2][i-1][j]+1;
            }
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            if(grid[i][j]==1){
                dp[1][i][j]=dp[1][i][j+1]+1;
                dp[3][i][j]=dp[3][i+1][j]+1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans=max(ans,max(dp[0][i][j],dp[1][i][j])+max(dp[2][i][j],dp[3][i][j]));
        }
    }
    cout << ans-1 << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    while(k--)solve();
}