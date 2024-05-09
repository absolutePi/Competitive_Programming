#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
const int N = 5005;
#define ll long long
ll dp[N];

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll q,k;
    cin >> q >> k;
    dp[0]=1;
    for(ll i=0;i<q;i++){
        string s;
        ll x;
        cin >> s >> x;
        if(s=="+"){
            for(ll i=k;i>=x;i--){
                dp[i]+=dp[i-x];
                dp[i]%=mod;
            }
        }
        else{
            for(ll i=x;i<=k;i++){
                dp[i] = (dp[i]-dp[i-x]+mod)%mod;
            }
        }
        cout << dp[k] << '\n';
    }
}