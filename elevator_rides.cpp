#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll n,x;
    cin >> n >> x;
    vector<ll> weights(n);
    for(auto &i : weights){cin >> i;}
    vector<pair<ll,ll>> dp(1<<n,{n+1,x+1});
    dp[0]={0,2e9};
    for(ll mask=1;mask<(1<<n);mask++){
        for(ll i=0;i<n;i++){
            if(mask&(1<<i)){
                ll prev=mask^(1<<i);
                ll rides=dp[prev].first;
                ll weight=dp[prev].second;
                if(weight+weights[i]>x){
                    rides++;
                    weight=weights[i];
                }
                else{
                    weight+=weights[i];
                }
                dp[mask]=min(dp[mask],{rides,weight});
            }
        }
    }
    cout << dp[(1<<n)-1].first;
}