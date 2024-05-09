#include <bits/stdc++.h>

using namespace std;

const int N = 1e9+7;
#define ll long long

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll n,x;
    cin >> n >> x;
    vector<ll> coin(n);
    vector<ll> dp(x+1);
    for(auto &i : coin){cin >> i;}
    dp[0]=1;
    for(ll j=0;j<n;j++){
        for(ll i=0;i<x;i++){
            if(i+coin[j]<=x){
                dp[i+coin[j]]+=dp[i];
                dp[i+coin[j]]%=N;
            }
        }
    }
    cout << dp[x] << '\n';
}   