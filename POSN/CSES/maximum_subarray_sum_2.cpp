#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MINF=-1e18;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,a,b;
    cin >> n >> a >> b;
    vector<ll> pref(n+1);
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        pref[i]=pref[i-1]+a;
    }
    multiset<ll> s;
    ll ans=MINF;
    for(int i=a;i<=n;i++){
        if(i>b){
            s.erase(s.find(pref[i-b-1]));
        }
        s.insert(pref[i-a]);
        ans=max(ans,pref[i]-*s.begin());
    }
    cout << ans << '\n';
}   