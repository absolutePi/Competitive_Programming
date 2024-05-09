#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    ll mn=0,mx=INT_MAX;
    for(ll i=1;i<n;i++){
        ll x = v[i-1];
        ll y = v[i];
        ll midl = (x+y)/2;
        ll midr = (x+y+1)/2;
        if(x<y){
            mx = min(mx,midl);
        }
        if(x>y){
            mn = max(mn,midr);
        }
    }
    if(mn<=mx){
        cout << mn << endl;
    }
    else cout << "-1" << endl;
}

int main(){
    ll t;
    cin >> t;
    for(ll i=0;i<t;i++){
        solve();
    }
}