#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll n,k;
    cin >> n >> k;
    vector<ll> primes(k);
    for(int i=0;i<k;i++){
        cin >>  primes[i];
    }
    vector<ll> sum_of_customs_contributer(k+1);//1-indexed
    for(ll i=1;i<(1<<k);i++){
        ll curr_contributer=0;
        ll temp=n;
        for(ll j=0;j<k;j++){
            if(i&(1<<j)){
                curr_contributer++;
                temp/=primes[j];
            }
        }
        sum_of_customs_contributer[curr_contributer]+=temp;
    }
    ll ans=0;
    for(ll i=1;i<=k;i++){
        if(i%2==0){
            ans-=sum_of_customs_contributer[i];
        }
        else{
            ans+=sum_of_customs_contributer[i];
        }
    }
    // for(int i=1;i<=3;i++){
    //     cout << sum_of_customs_contributer[i] << endl;
    // }
    cout << ans;
}  