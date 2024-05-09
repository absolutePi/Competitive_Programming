#include <bits/stdc++.h>

using namespace std;
#define ll long long 

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll t;
    cin >> t;
    for(ll c=0;c<t;c++){
        ll n,q,L,R;
        cin >> n >> q;
        vector<ll> prf_sum(n+1,0);
        vector<ll> prf_xor(n+1,0);
        for(ll i=1;i<=n;i++){
            ll x;
            cin >> x;
            prf_sum[i]=prf_sum[i-1]+x;
            prf_xor[i]=prf_xor[i-1]^x;
        }
        cin >> L >> R;
        auto func = [&](ll l,ll r){
            return (prf_sum[r]-prf_sum[l-1])-(prf_xor[r]^prf_xor[l-1]);
        };
        ll best = func(1,n);
        ll l=1,r=n,range;
        while(l<r){
            bool pos=false;
            range = l+(r-l)/2;
            for(ll i=1;i+range-1<=n;i++){
                if(func(i,i+range-1)==best){
                    pos=true;
                    break;
                }
            }
            if(pos){
                r=range;
            }
            else{
                l=range+1;
            }
        }
        for(ll i=1;i+l-1<=n;i++){
            if(func(i,i+l-1)==best){
                cout << i << ' ' << i+l-1 << endl;
                break;
            }
        }
    }
}