#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("cowjog.in","r",stdin);
    freopen("cowjog.out","w",stdout);
    ll n,t;
    cin >> n >> t;
    vector<pair<ll,ll>> v(n);
    for(ll i=0;i<n;i++){
        ll a,s;
        cin >> a >> s;
        v[i]={a,a+s*t};
    }
    sort(v.begin(),v.end(),greater<pair<ll,ll>>());
    multiset<ll> s;
    ll lane=0;
    for(ll i=0;i<n;i++){
        if(s.upper_bound(v[i].second)==s.end()){
            lane++;
        }
        else{
            s.erase(s.upper_bound(v[i].second));
        }
        s.insert(v[i].second);
    }
    cout << lane << '\n';
}
