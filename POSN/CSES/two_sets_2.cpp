#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5;
const int mod = 1e9+7;
#define ll long long
ll dp[N];
 
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll n;
    cin >> n;
    ll target = (n*(n+1))/2;
    if(target%2){
        cout << 0 << '\n';
        return 0;
    }
    target/=2;
    dp[0]=1;
    for(ll i=1;i<n;i++){
        for(ll j=target;j>=i;j--){
            dp[j]+=dp[j-i];
            dp[j]%=mod;
        }
    }
    // for(ll i=0;i<=target;i++){cout << dp[i] << ' ';}
    cout << dp[target] << '\n';
}   
