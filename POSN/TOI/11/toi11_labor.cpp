#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll INF = 1e12+5;
ll n;
ll m;
vector<ll> v;

bool works(ll time){
    ll transported=0;
    for(ll i=0;i<n;i++){
        if(time/v[i]==0){break;}
        transported+=(time/v[i]);
    }
    return transported>=m;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> m;
    v.resize(n);
    for(auto &i : v){cin >> i;}
    sort(v.begin(),v.end());
    ll l=0,r=INF,t,ans;
    while(l<=r){
        t=l+(r-l)/2;
        if(works(t)){
            ans=t;
            r=t-1;
        }
        else{
            l=t+1;
        }
    }
    cout << ans << '\n';
}