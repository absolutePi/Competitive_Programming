#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(105,0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v[x]++;
    }
    int ans=0;
    for(int i=0;i<105;i++){
        ans+=(v[i])/3;
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}