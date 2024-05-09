#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

int main(){
    //ios::sync_with_stdio(false);
    //in.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> ans(n+1);
    map<ll,ll> m;
    for(ll i=0;i<n;i++){
        ll l,r;
        cin >> l >> r;
        m[l]++;
        m[r+1]--;
    }
    auto it = m.begin();
    ll last = it->s;
    auto myend = m.end();
    myend--;
    for(auto it=m.begin();it!=myend;it++){
        auto it2 = it;
        it2++;
        ans[last]+=it2->f-it->f;
        last+=it2->s;
    }
    for(ll i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
}