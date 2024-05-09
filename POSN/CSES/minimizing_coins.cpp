#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll n,x;//coin nums and desired sum
    cin >> n >> x;
    vector<ll> coin(n);
    for(auto &i : coin){cin >> i;}
    vector<ll> dp(x+1,INT_MAX);
    dp[0]=0;
    for(ll i=0;i<x;i++){
        for(ll j=0;j<n;j++){
            if(i+coin[j]<=x){
                dp[i+coin[j]]=min(dp[i+coin[j]],dp[i]+1);
            }
        }
    }
    if(dp[x]==INT_MAX){cout << "-1";}
    else{
        cout << dp[x] << '\n';
    }
}   