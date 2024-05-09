#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int n,x;
    ll ans=0;
    cin >> n >> x;
    vector<ll> prefixes(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> prefixes[i];
        prefixes[i]+=prefixes[i-1];
    }
    map<ll,int> cnt;
    cnt[0]=1;
    for(int i=1;i<=n;i++){
        ans+=cnt[prefixes[i]-x];
        cnt[prefixes[i]]++;
    }   
    cout << ans;
}