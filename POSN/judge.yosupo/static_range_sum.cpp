#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ll n,q;
    cin >> n >> q;
    vector<ll> v(n+1,0);
    for(ll i=1;i<=n;i++){
        cin >> v[i];
        v[i]+=v[i-1];
    }
    for(ll i=0;i<q;i++){
        ll l,r;
        cin >> l >> r;
        cout << v[r]-v[l] << endl;
    }
}