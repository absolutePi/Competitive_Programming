#include <bits/stdc++.h>

using namespace std;

const int N =1e5+5;
#define ll long long
ll skill[N][7];
ll dp[N][1<<7];

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll n,p,k;
    cin >> n >> p >> k;
    memset(dp,-1,sizeof(dp));
    vector<pair<ll,ll>> aud(n+1);
    for(ll i=1;i<=n;i++){
        ll x;
        cin >> x;
        aud[i]={x,i};
    }
    sort(aud.begin()+1,aud.end(),greater<pair<ll,ll>>());
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<p;j++){
            cin >> skill[i][j];
        }
    }
    dp[0][0]=0;
    for(ll i=1;i<=n;i++){
        ll x=aud[i].second;
        for(ll mask=0;mask<(1<<7);mask++){
            ll z=i-__builtin_popcount(mask)-1;
            if(z<k){
                if(dp[i-1][mask]!=-1){
                    dp[i][mask]=dp[i-1][mask]+aud[x].first;
                }
            }
            else{
                if(dp[i-1][mask]!=-1){
                    dp[i][mask]=dp[i-1][mask];
                }
            }
            for(ll pos=0;pos<p;pos++){
                if(mask&(1<<pos)&&dp[i-1][mask^(1<<pos)]!=-1){
                    dp[i][mask]=max(dp[i][mask],dp[i-1][mask^(1<<pos)]+skill[x][pos]);
                }
            }
        }
    }
    cout << dp[n][(1<<p)-1];
}