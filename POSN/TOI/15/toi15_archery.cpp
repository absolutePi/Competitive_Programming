#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int N = 500000;
pair<ll,ll> p[N];//pos of holes,height
ll prf[N],pos;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,sum=0,min_height=LONG_MAX,ans=LONG_MAX;
    cin >> n;
    for(ll i=1;i<=n;i++){
        cin >> p[i].second;
        min_height=min(min_height,p[i].second);
    }
    for(ll i=1;i<=n;i++){
        cin >> p[i].first;
        sum+=p[i].first;
    }
    sort(p+1,p+1+n);
    for(ll i=1;i<=n;i++){
        prf[i]=prf[i-1]+p[i].second;
    }
    for(ll i=1;i<=n;i++){
        if(p[i].first>min_height){break;}
        ll curr=prf[i-1]+sum-(p[i].first*n);
        if(curr<ans){
            ans=curr;
            pos=p[i].first;
        }
    }
    cout << pos << ' ' << ans << '\n';
}   