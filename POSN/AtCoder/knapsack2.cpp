#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
const int INF = INT_MAX;
int w[N],v[N],dp[N];

int main(){
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> w[i] >> v[i];
    }
    for(int i=1;i<N;i++){
        dp[i]=INF;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=N-1;j>=v[i];j--){
            if((dp[j-v[i]]!=INF)&&(dp[j-v[i]]+w[i])<=k)dp[j]=min(dp[j],dp[j-v[i]]+w[i]);
            if(dp[j]!=INF){
                ans=max(ans,j);
            }
        }
    }
    // cout << dp[0] << '\n';
    // cout << dp[30] << ' ' << dp[50] << ' ' << dp[60] << ' ' << dp[80] << ' ' << dp[90] << ' ' << dp[110];
    cout << ans << '\n';
}


