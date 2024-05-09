#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ll k,n,w;
    cin >> k >> n >> w;
    int ans = ((w*(w+1))/2)*k-n;
    if(ans<0)ans=0;
    cout << ans;
}