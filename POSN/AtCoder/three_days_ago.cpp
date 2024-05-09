#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    string str;
    cin >> str;
    ll curr_xor = 0;
    map<ll,ll> m;
    m[curr_xor]++;
    for(auto i : str){
        curr_xor^= 1 << (i-'0');
        m[curr_xor]++;
    }
    ll ans=0;
    for(auto [_,i] : m){
        ans+=(i*(i-1))/2;
    }
    cout << ans << endl;
}