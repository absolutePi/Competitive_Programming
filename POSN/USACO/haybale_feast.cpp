#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll INF = 1e10;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("hayfeast.in","r",stdin);
    freopen("hayfeast.out","w",stdout);
    ll n,m;
    cin >> n >> m;
    multiset<ll> spicies;
    vector<pair<ll,ll>> v(n);//{flavor,spiciness}
    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
    ll r=-1,sum=0,spice=0;
    ll ans=INF;
    for(int l=0;l<n;l++){
        while(sum<m&&(r+1<n)){
            r++;
            sum+=v[r].first;
            spice=max(spice,v[r].second);
            spicies.insert(v[r].second);
        }
        if(sum>=m){
            ans=min(ans,spice);
        }
        sum-=v[l].first;
        spicies.erase(spicies.find(v[l].second));
        if(spicies.size()){
            spice=*spicies.rbegin();
        }
    }
    cout << ans << '\n';
}
