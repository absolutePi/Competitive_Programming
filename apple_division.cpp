#include <bits/stdc++.h>

using namespace std;

using ll = long long;
ll n,sum1,sum2;
vector<ll> weight;

ll recur_apple(ll k,ll sum1,ll sum2){
    if(k==n){
        return abs(sum1-sum2);
    }
    return min(recur_apple(k+1,sum1+weight[k],sum2),recur_apple(k+1,sum1,sum2+weight[k]));
}

int main(){
    cin >> n;
    weight.resize(n);
    for(ll i=0;i<n;i++){cin >> weight[i];}
    cout << recur_apple(0,0,0);
}