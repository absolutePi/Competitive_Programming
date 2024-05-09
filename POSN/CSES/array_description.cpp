#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
#define ll long long

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll n,m;
    cin >> n >> m;
    vector<ll> v(n);
    for(auto &i : v){cin >> i;}
    vector<vector<ll>> dp(n,vector<ll>(m+1,0));
    if(v[0]==0){
        for(ll num=1;num<=m;num++){
            dp[0][num]=1;
        }
    }
    else{
        dp[0][v[0]]=1;
    }
    for(ll i=1;i<n;i++){
        if(v[i]==0){
            for(ll j=1;j<=m;j++){
                dp[i][j]+=dp[i-1][j];
                if(j-1>0){
                    dp[i][j]+=dp[i-1][j-1];
                }
                if(j+1<=m){
                    dp[i][j]+=dp[i-1][j+1];
                }
                dp[i][j]%=MOD;
            }
        }
        else{
            dp[i][v[i]]+=dp[i-1][v[i]];
            if(v[i]-1>0){
                dp[i][v[i]]+=dp[i-1][v[i]-1];
            }
            if(v[i]+1<=m){
                dp[i][v[i]]+=dp[i-1][v[i]+1];
            }
            dp[i][v[i]]%=MOD;
        }
    }
    ll ans=0;
    for(ll i=1;i<=m;i++){
        ans+=dp[n-1][i];
        ans%=MOD;
    }
    cout << ans << '\n';
}