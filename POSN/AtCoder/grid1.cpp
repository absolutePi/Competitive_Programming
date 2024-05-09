#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+5;
const int MOD = 1e9+7;
char a[N][N];
int dp[N][N];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]!='#'){
                if(j)dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
                if(i)dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
            }
        }
    }
    cout << dp[n-1][m-1];
}