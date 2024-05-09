#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+1;
#define ll long
ll dp[N];

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> coin(n);
    for(auto &i : coin){cin >> i;}
    dp[0]=1;
    ll ans=0;
    for(ll i=0;i<n;i++){
        for(ll j=N;j>=coin[i];j--){
            dp[j]+=dp[j-coin[i]];
        }
    }
    vector<ll> res;
    for(ll i=1;i<=N;i++){
        if(dp[i]){
            res.push_back(i);
        }
    }
    cout << res.size() << '\n';
    for(auto i : res){cout << i << ' ';}
}   