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
    vector<ll> sticks(n);
    for(ll &i : sticks){cin >> i;}
    sort(all(sticks));
    ll cost = 0;
    ll chosen = sticks[n/2];
    for(ll i=0;i<n;i++){
        cost+=abs(chosen-sticks[i]);
    }
    cout << cost;
}