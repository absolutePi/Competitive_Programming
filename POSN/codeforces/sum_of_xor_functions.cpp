#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> prf_xor(n+1,0);
    for(ll i=1;i<=n;i++){
        ll x;
        cin >> x;
        prf_xor[i]=prf_xor[i-1]^x;
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=n;j++){
            ans+=(prf_xor[j]^prf_xor[i-1])*(j-i+1);
        }
    }
    cout << (ans%998244353);
}//skipped