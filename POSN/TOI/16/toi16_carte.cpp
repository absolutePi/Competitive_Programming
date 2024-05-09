#include <bits/stdc++.h>

using namespace std;

const int N = 405;
const int INF=2e9;
int r,k,ans=INT_MIN;
int dp[N][N];
int a[N];

void solve(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        dp[i][i]=1;
    }
    for(int sz=2;sz<=n;sz++){
        for(int l=1;l+sz-1<=n;l++){
            int r=l+sz-1;
            dp[l][r]=INF;
            for(int mid=l;mid<r;mid++){
                dp[l][r]=min(dp[l][r],dp[l][mid]+dp[mid+1][r]);
            }
            if(a[l]==a[r])dp[l][r]--;
        }
    }
    ans=max(ans,dp[1][n]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> r >> k;
    for(int i=0;i<r;i++){
        solve();
    }
    cout << ans << '\n';
}   