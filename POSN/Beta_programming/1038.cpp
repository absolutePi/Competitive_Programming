#include <bits/stdc++.h>

using namespace std;

const int N = 20;
double dp[(1<<N)];
double a[N][N];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
            a[i][j]/=100;
        }
    }
    dp[0]=1;
    for(int s=0;s<(1<<n);s++){
        if(dp[s]==0)continue;
        for(int i=0;i<n;i++){
            if((s&(1<<i))==0){
                int curr=(s^(1<<i));
                int j=__builtin_popcount(s);
                dp[curr]=max(dp[curr],dp[s]*a[i][j]);
            }
        }
    }
    cout << fixed << setprecision(12) << dp[(1<<n)-1]*100;
    // cout << dp[(1<<n)];
}