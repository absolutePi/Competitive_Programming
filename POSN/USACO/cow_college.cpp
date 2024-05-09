#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll N = 1e6+1;
ll cnt[N];

int main(){
    ll n,mx=INT_MIN,charge;
    cin >> n;
    ll temp = n;
    for(ll i=0;i<n;i++){
        ll x;
        cin >> x;
        cnt[x]++;
    }
    for(ll i=1;i<=N;i++){
        if(cnt[i]){
            ll total = i*temp;
            if(total>mx){
                mx = total;
                charge = i;
            }
            temp-=cnt[i];
        }
    }
    cout << mx << " " << charge;
}