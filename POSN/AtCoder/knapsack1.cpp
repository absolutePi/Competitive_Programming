#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1e5+5;    
int w[N],v[N],dp[N];

signed main(){
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> w[i] >> v[i];
    }
    for(int i=0;i<n;i++){
        for(int j=k;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout << dp[k] << '\n';
}