#include <bits/stdc++.h>

using namespace std;

int factorize(int n){
    int ans=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            ans+= i*i==n ? 1 : 2;
        }
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    cout << factorize(n) << endl;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        solve();
    }
}