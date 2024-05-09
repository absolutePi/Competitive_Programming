#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll arr[55][1005];//days and cows

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll c,n,m;
    cin >> c >> n >> m;
    for(ll i=0;i<n;i++){
        ll x;
        cin >> x;
        arr[0][x]++;
    }
    for(ll day=0;day<=50;day++){
        for(ll cows=1;cows<=c;cows++){
            if(cows*2<=c){
                arr[day+1][cows*2]+=arr[day][cows];
            }
            else{
                arr[day+1][cows]+=2*arr[day][cows];
            }
        }
    }
    for(ll i=0;i<m;i++){
        ll x,ans=0;
        cin >> x;
        for(ll i=1;i<=c;i++){
            ans+=arr[x][i];
        }
        cout << ans << '\n';
    }
}