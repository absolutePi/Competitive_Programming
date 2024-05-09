#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll n,ans=0;
    cin >> n;
    for(ll i=2;i*i<=n;i++){
        ll xpo=0;
        while(n%i==0){
            xpo++;
            // xpo-=j;
        }
    }
    if(n>1)ans++;
    cout << ans;
}