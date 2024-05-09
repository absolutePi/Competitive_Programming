#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1000;
const int MOD = 1e9+7;
ll dp[N][N];
bool matrix[N][N];

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;
            cin >> c;
            matrix[i][j]= c=='.';//trap==false
        }
    }
    dp[0][0]=matrix[0][0] ? 1 : 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!matrix[i][j]){continue;}
            if(i==0&&j==0){continue;}
            if(j>0){
                dp[i][j]+=dp[i][j-1];
                dp[i][j]%=MOD;
            }
            if(i>0){
                dp[i][j]+=dp[i-1][j];
                dp[i][j]%=MOD;
            }
        }
    }
    cout << dp[n-1][n-1] << '\n';
}