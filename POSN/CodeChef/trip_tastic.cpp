#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n,m,k;
vector<vector<ll>> arr;
vector<vector<ll>> prefix;

bool check(ll mid){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]){
                ll total=prefix[min(i+mid+1,n)][min(j+mid+1,m)]
                    -prefix[min(i+mid+1,n)][max(0LL,j-mid)]
                    -prefix[max(i-mid,0LL)][min(j+mid+1,m)]
                    +prefix[max(i-mid,0LL)][max(j-mid,0LL)];
                if(total>=k+1){return true;}
            }
        }
    }
    return false;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin >> t;
    for(ll i=0;i<t;i++){
        cin >> n >> m >> k;
        arr = vector<vector<ll>>(n,vector<ll>(m));
        prefix = vector<vector<ll>>(n+1,vector<ll>(m+1,0));
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){  
                cin >> arr[i][j];
                prefix[i+1][j+1]=arr[i][j]
                +prefix[i][j+1]
                +prefix[i+1][j]
                -prefix[i][j];
        }
    }
        ll l=0,r=max(m,n),ans=-1;
        while(l<r){
            ll mid = l+(r-l)/2;
            if(check(mid)){
                r=mid;
                ans=mid;
            }
            else{
                l=mid+1;
            }
        }
        cout << ans << endl;
    }
}