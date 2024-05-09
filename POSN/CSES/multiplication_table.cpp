#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll n;
    cin >> n;
    ll l=1,r=n*n;
    while(l<r){
        ll sum=0;
        ll mid=(l+r)/2;
        for(int i=1;i<=n;i++){
            sum+=min(n,mid/i);
        }
        if(sum>=((n*n+1)/2)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout << l;
}