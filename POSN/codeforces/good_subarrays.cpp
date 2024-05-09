#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<int> prefix(n+1);
    for(int i=1;i<=n;i++){
        char c;
        cin >> c;
        prefix[i]=c-'0';
        prefix[i]+=prefix[i-1];
    }
    map<int,ll> m;
    for(int i=0;i<=n;i++){
        m[prefix[i]-i]++;
    }
    ll ans=0;
    for(auto i : m){
        ans+=i.second*(i.second-1)/2;
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}