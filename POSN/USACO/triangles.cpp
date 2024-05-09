#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    freopen("triangles.in","r",stdin);
    freopen("triangles.out","w",stdout);
    ll n;
    cin >> n;
    vector<pair<ll,ll>> v(n);
    for(ll i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
    //find max x and max y of each position
    ll mxx,mxy,mxans=0;
    for(ll i=0;i<n;i++){
        mxx=0,mxy=0;
        for(ll j=0;j<n;j++){
            if(i!=j){
                //parallel with x(y1=y2)
                if(v[i].second==v[j].second){
                    mxx = max(mxx,abs(v[i].first-v[j].first));
                }
                //parallel with y(x1=x2)
                if(v[i].first==v[j].first){
                    mxy = max(mxy,abs(v[i].second-v[j].second));
                }
            }
        }
        mxans = max(mxans,mxx*mxy);
    }
    cout << mxans;
}