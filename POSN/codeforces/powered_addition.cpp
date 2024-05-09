#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(auto &i : arr){
        cin >> i;
    }
    ll curr_pos_plus=0,x=0;
    for(ll i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){continue;}
        else{
            while(curr_pos_plus+arr[i]<arr[i-1]){
                x++;
                curr_pos_plus += 1 << (x-1);
            }
            arr[i]=arr[i-1];
        }
    }
    cout << x << endl;
    return;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll t;
    cin >> t;
    for(ll i=0;i<t;i++){
        solve();
    }
}