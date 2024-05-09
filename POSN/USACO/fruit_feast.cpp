#include <bits/stdc++.h>

using namespace std;

const int N = 5e6+1;
bool dp[N][2];//[fullness][1==drank]=pos?

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("feast.in","r",stdin);
    freopen("feast.out","w",stdout);
    int T,A,B;
    cin >> T >> A >> B;
    dp[0][0]=true;
    for(int i=0;i<=T;i++){
        if(i-A>=0){dp[i][0]|=dp[i-A][0];}
        if(i-B>=0){dp[i][0]|=dp[i-B][0];}
        dp[i/2][1]|=dp[i][0];
    }
    for(int i=0;i<=T;i++){
        if(i-A>=0){dp[i][1]|=dp[i-A][1];}
        if(i-B>=0){dp[i][1]|=dp[i-B][1];}
    }
    for(int i=T;i>=0;i--){
        if(dp[i][1]){
            cout << i << '\n';
            return 0;
        }
    }
}