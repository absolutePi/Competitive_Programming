#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD=1e9+7;
const ll N = 305;
const ll K = 15;
ll prf[N],n,k,d,dp[N][N][K];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> d;
    for(ll i=1;i<=n;i++){
        ll a;
        cin >> a;
        prf[i]=prf[i-1]+a;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=n;j++){
            dp[i][j][1]=1;
        }
    }
    for(ll level=2;level<=k;level++){
        for(ll l=n;l>=0;l--){
            for(ll r=l+1;r<=n;r++){
                for(ll mid=l;mid<r;mid++){
                    if(abs((prf[mid]-prf[l-1])-(prf[r]-prf[mid]))<=d){
                        dp[l][r][level]+=(dp[l][mid][level-1]*dp[mid+1][r][level-1])%MOD;
                        dp[l][r][level]%=MOD;
                    }
                }
            }
        }
    }
    cout << dp[1][n][k] << '\n';
}   