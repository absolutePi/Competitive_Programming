#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
double p[N];
double dp[N][N];//dp[i][j] threw i times, j times are heads

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> p[i];
    }
    dp[1][0]=(1-p[1]),dp[1][1]=p[1];
    for(int i=2;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(j)dp[i][j]+=(dp[i-1][j-1]*p[i]);
            dp[i][j]+=(dp[i-1][j]*(1-p[i]));
        }
    }
    double ans=0;
    for(int i=(n/2)+1;i<=n;i++){
        ans+=dp[n][i];
    }
    cout << fixed << setprecision(15) << ans << '\n';
}