#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n,k,arr[805][805];

ll cal_prefix(ll i,ll j,vector<vector<ll>> &pref){
    return pref[i][j]-pref[i][j-k]-pref[i-k][j]+pref[i-k][j-k];
}
bool works(ll curr_median){
    vector<vector<ll>> prefix(n+1,vector<ll>(n+1));
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=n;j++){
            prefix[i][j]=0;
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+(arr[i-1][j-1]>curr_median);
            if(i>=k && j>=k && cal_prefix(i,j,prefix)<k*k/2+1){
                return true;
            }
        }
    }
    return false;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> k;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    ll l=-1,r=1e9+5,mid;
    while(l<r){
        mid = l+(r-l)/2;
        if(works(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout << l << '\n';
}   