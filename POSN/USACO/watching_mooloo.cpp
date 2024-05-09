#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int N = 1e5+1;

int main(){
    ll n,k;
    cin >> n >> k;
    ll prevd,prev = 1 + k;
    cin >> prevd;n--;
    while(n--){
        ll curd;
        cin >> curd;
        prev = min(curd-prevd+prev,1+k+prev);
        prevd = curd;
    }
    cout << prev;
}