#include <bits/stdc++.h>

using namespace std;

const int N = 300;
bool dp[N][N][3];
int n;
string str;

void solve(){
    cin >> n >> str;
    memset(dp,false,sizeof(dp));
    for(int i=0;i<n;i++){
        dp[i][i][str[i]-'0']=true;
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
            for(int k=i;k<j;k++){
                dp[i][j][2]|=(dp[i][k][0]&&dp[k+1][j][0]);
                dp[i][j][1]|=(dp[i][k][0]&&dp[k+1][j][1]);
                dp[i][j][0]|=(dp[i][k][0]&&dp[k+1][j][2]);
                dp[i][j][2]|=(dp[i][k][1]&&dp[k+1][j][0]);
                dp[i][j][1]|=(dp[i][k][1]&&dp[k+1][j][1]);
                dp[i][j][1]|=(dp[i][k][1]&&dp[k+1][j][2]);
                dp[i][j][1]|=(dp[i][k][2]&&dp[k+1][j][0]);
                dp[i][j][2]|=(dp[i][k][2]&&dp[k+1][j][1]);
                dp[i][j][1]|=(dp[i][k][2]&&dp[k+1][j][2]);
            }
        }
    }
    if(dp[0][n-1][0]){
        cout << "yes" << '\n';
    }
    else cout << "no" << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<20;i++){
        solve();
    }
}   