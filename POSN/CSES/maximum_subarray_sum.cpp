#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    ll total = v[0],ans=v[0];
    for(int i=1;i<n;i++){
        total = (total+v[i]>v[i]) ? total+v[i] : v[i];
        ans = max(ans,total);
    }
    cout << ans;
}