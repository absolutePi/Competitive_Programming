#include <bits/stdc++.h>

using namespace std;

const int N = 21;
const int MOD = 1e9+7;
bool compatible[N][N];
int dp[1<<N];

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> compatible[i][j];
        }
    }
    dp[0]=1;
    for(int s=0;s<(1<<n);s++){
        int pair_num= __builtin_popcount(s);
        for(int w=0;w<n;w++){
            if(s&(1<<w) || !compatible[pair_num][w]){continue;}
            dp[s|(1<<w)]+=dp[s];
            dp[s|(1<<w)]%=MOD;
        }
    }
    cout << dp[(1<<n)-1];
}