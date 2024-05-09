#include <bits/stdc++.h>

using namespace std;

const int N = 1e9+7;
#define ll long long

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> dp(n+1);
    dp[0]=1;
    for(ll i=0;i<n;i++){//i=current sum
        for(ll j=1;j<=6;j++){
            if(i+j>n){break;}
            dp[i+j]+=dp[i];
            dp[i+j]%=N;
        }
    }
    cout << dp[n] << '\n';
}   