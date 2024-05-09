#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll N,K;
vector<ll> v;

bool good(ll max_sum){
    ll total=0;
    ll arr=1;
    for(ll i=0;i<N;i++){
        if(v[i]>max_sum){return false;}
        if(total+v[i]>max_sum){
            arr++;
            total=v[i];
            if(arr>K){return false;}
        }
        else{
            total+=v[i];
        }
    }
    return arr<=K;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> N >> K;
    v.resize(N);
    for(auto &i : v){cin >> i;}
    ll l=0,r=1e18;
    while(l<r){
        ll mid = l+(r-l)/2;
        if(good(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout << l;
}