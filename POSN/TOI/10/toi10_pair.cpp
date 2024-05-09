#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
char a[N];
int dp[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }    
    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                dp[i][j]=dp[i+1][j-1]+1;
            }
            for(int k=i;k<j;k++){
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
    }
    cout << dp[0][n-1] << '\n';
}