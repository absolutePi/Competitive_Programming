#include <bits/stdc++.h>

using namespace std;
#define ll long long 

ll n,arr[100000],k,pf[100001];
//arr will be 0-indexed
//pf will be 1-indexed

bool check(ll dif){
    for(int lp=0;lp<n;lp++){
        ll rp=upper_bound(arr,arr+n,arr[lp]+dif)-arr;
        ll need=lp*arr[lp]-pf[lp];//left side
        need+=pf[n]-pf[rp]-(n-rp)*(arr[lp]+dif);
        if(need<=k){return true;}
    }
    for(int rp=0;rp<n;rp++){
        ll lp=lower_bound(arr,arr+n,arr[rp]-dif)-arr;
        ll needed=lp*(arr[rp]-dif)-pf[lp]+pf[n]-pf[rp]-(n-rp)*arr[rp];
        if(needed<=k){return true;}
    }
    return false;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        pf[i+1]=pf[i]+arr[i];
    }
    ll l=0,r=1e9;
    while(l<r){
        ll mid=l+(r-l)/2;
        if(check(mid)){
            r=mid;
        }
        else l=mid+1;
    }
    cout << l;
}