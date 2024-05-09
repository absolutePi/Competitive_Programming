#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<pair<ll,char>> v;
    for(ll t=0;t<n;t++){
        char c;
        ll x;
        cin >> c >> x;
        v.push_back({x,c});
    }
    sort(v.begin(),v.end());
    vector<ll> cnt(n);
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(i!=j){
                if(v[j].first>v[i].first&&v[j].second=='G')cnt[i]++;
                else if(v[j].first<v[i].first&&v[j].second=='L')cnt[i]++;
            }
        }
    }
    ll mn;
    for(ll i=0;i<n;i++){
        mn = min(mn,cnt[i]);
    }
    cout << mn;
}