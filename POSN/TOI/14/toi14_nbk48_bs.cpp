#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int prf[N],n,q;

void solve(){
    int m;
    cin >> m;
    int l=0,r=n,mid,ans;
    while(l<=r){
        mid=l+(r-l)/2;
        if(prf[mid]>m){
            r=mid-1;
        }
        else{
            l=mid+1;
            ans=mid;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        prf[i]=prf[i-1]+a;
    }
    int temp=prf[n];
    for(int i=n-1;i>=1;i--){
        if(temp>prf[i])temp=prf[i];
        if(temp<prf[i])prf[i]=temp;
    }
    for(int i=0;i<q;i++){
        solve();
    }
}