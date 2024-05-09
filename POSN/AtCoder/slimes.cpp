#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 405;
int a[N],dp[N][N];

signed main(){
    int n;
    cin >> n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=LLONG_MAX;
        }
    }
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i]+=a[i-1];
        dp[i][i]=0;
    }
    for(int l=2;l<=n;l++){
        for(int i=1;i+l-1<=n;i++){
            int j=i+l-1;
            for(int k=i;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+a[j]-a[i-1]);
            }
        }
    }
    cout << dp[1][n];
}
