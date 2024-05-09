#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> m(n);
    ll prefix = 0;
    m[prefix] = 1;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        prefix+=x;
        m[(prefix%n+n)%n]++;
    }
    ll ans=0;
    for(ll i : m){
        ans+= (i*(i-1))/2;
    }
    cout << ans;
}