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
    vector<pair<ll,ll>> v(n);//duration and deadline
    for(auto &i : v){cin >> i.f >> i.s;}
    sort(all(v));
    ll time=0,ans=0;
    for(ll i=0;i<n;i++){
        time+=v[i].f;
        ans+=v[i].s-time;
    }
    cout << ans;
}