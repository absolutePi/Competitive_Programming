#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll N,T;//number of machines and number of products required to produce
vector<ll> machines;

bool good(ll time){
    ll total=0;
    for(ll i=0;i<N;i++){
        total+=time/machines[i];
        if(total>T){return true;}
    }
    return total>=T;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> N >> T;
    machines.resize(N);
    for(auto &i : machines){cin >> i;}

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