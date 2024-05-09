#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+5;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n+1),prefix(n+2),suffix(n+2);
    prefix[0]=0;
    suffix[0]=0,suffix[n+1]=-1e9;
    //containing values
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }    
    //pushing prefix
    for(int i=1;i<=n;i++){
        prefix[i] = max(prefix[i-1],v[i]+i);
    }
    //pushing suffix
    for(int i=n;i>=1;i--){
        suffix[i] = max(suffix[i+1],v[i]-i);
    }
    int ans = 0;
    //selecting the mid_max
    for(int i=2;i<n;i++){
        ans = max(ans,v[i]+prefix[i-1]+suffix[i+1]);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}