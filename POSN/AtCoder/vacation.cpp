#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
vector<vector<int>> v(N,vector<int>(3));
int dp[N][3];

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(j!=k){
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+v[i][j]);
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<3;i++){
        ans=max(ans,dp[n][i]);
    }
    cout << ans << '\n';
}