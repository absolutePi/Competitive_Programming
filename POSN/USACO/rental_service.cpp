#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    freopen("rental.in","r",stdin);
    freopen("rental.out","w",stdout);
    ll n,m,r;
    cin >> n >> m >> r;

    ll milk[n];
    for(ll i=0;i<n;i++){
        cin >> milk[i];
    }
    sort(milk,milk+n,greater<ll>());

    vector<pair<ll,ll>> buy_milk;//price and gallons(switched for sorting)
    for(ll i=0;i<m;i++){
        ll gallon,price;
        cin >> gallon >> price;
        buy_milk.push_back({price,gallon});
    }
    sort(buy_milk.begin(),buy_milk.end(),greater<pair<ll,ll>>());

    ll rent_cow[r];
    for(ll i=0;i<r;i++){
        cin >> rent_cow[i];
    }
    sort(rent_cow,rent_cow+r,greater<ll>());

    ll mxProfit[n+1];
    mxProfit[0]=0;

    //milk
    ll storei=0;
    for(ll i=0;i<n;i++){
        mxProfit[i+1] = mxProfit[i];
        while(storei<m && milk[i]>0){
            ll used = min(milk[i],buy_milk[storei].second);
            mxProfit[i+1] += used*buy_milk[storei].first;
            milk[i]-=used;
            buy_milk[storei].second-=used;
            if(buy_milk[storei].second==0)storei++;
        }
    }

    //rent 
    ll rent_money_sofar=0;

    ll renti=0,i=n-1;
    while(renti<r && i>=0){
        rent_money_sofar+=rent_cow[renti];
        mxProfit[i]+=rent_money_sofar;
        renti++;i--;
    }
    ll res = *max_element(mxProfit,mxProfit+n+1);

    cout << res;
}