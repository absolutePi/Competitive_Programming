#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+1;
#define ll long long
ll dp[N];

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll n,x;
    cin >> n >> x;
    vector<ll> price(n),pages(n);
    for(auto &i : price){cin >> i;}
    for(auto &i : pages){cin >> i;}
    dp[0]=0;
    for(ll i=0;i<n;i++){//books
        for(ll j=x;j>=price[i];j--){
            dp[j]=max(dp[j],dp[j-price[i]]+pages[i]);
        }
    }
    ll mx=INT_MIN;
    for(ll i=0;i<=x;i++){
        mx = max(mx,dp[i]);
    }
    cout << mx << '\n';
}