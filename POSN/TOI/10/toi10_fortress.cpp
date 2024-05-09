#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int m,n;
    cin >> m >> n;
    int b=(m/2)-n;
    if((n-b<0)||(m%2)||(b<0)){
        cout << 0 << '\n';
        return;
    }
    else cout << n-b+1 << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<20;i++){
        solve();
    }
}