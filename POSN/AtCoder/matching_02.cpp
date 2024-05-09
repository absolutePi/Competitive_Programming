#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
const int N = 21;
int dp[(1<<N)],a[N][N];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    dp[0]=1;
    for(int state=0;state<(1<<n);state++){
        int pair_num=__builtin_popcount(state);
        for(int women=0;women<n;women++){
            if(state&(1<<women) || !a[pair_num][women])continue;
            dp[state|(1<<women)]=(dp[state|(1<<women)]+dp[state])%MOD;
        }
    }
    cout << dp[(1<<n)-1];
}   