#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll N = 1005;
ll arr[N][N],pref[N][N];

void solve(){
    ll n,q;
    cin >> n >> q;
    for(ll i=0;i<N;i++){
        for(ll j=0;j<N;j++){
            arr[i][j] = pref[i][j] = 0;
        }
    }
    for(ll i=0;i<n;i++){
        ll h,w;
        cin >> h >> w;
        arr[h][w]+=h*w;
    }
    for(ll i=1;i<N;i++){
        for(ll j=1;j<N;j++){
            pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+arr[i][j];
        }
    }
    for(ll i=0;i<q;i++){
        ll hs,ws,hb,wb;
        cin >> hs >> ws >> hb >> wb;
        cout << pref[hb-1][wb-1]-pref[hb-1][ws]-pref[hs][wb-1]+pref[hs][ws] << '\n';
    }
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll t;
    cin >> t;
    for(ll i=0;i<t;i++){
        solve();
    }
}   