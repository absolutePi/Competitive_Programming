#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
const int INF = 2e9;
int h[N],dp[N];

int main(){
    int n,k;
    cin >> n >> k;
    for(int i=1;i<n;i++){
        dp[i]=INF;
    }
    for(int i=0;i<n;i++){
        cin >> h[i];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            if(i-j>=0)dp[i]=min(dp[i],dp[i-j]+abs(h[i]-h[i-j]));
        }
    }
    cout << dp[n-1] << '\n';
}