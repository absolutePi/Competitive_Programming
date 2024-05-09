#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i : v){cin >> i;}
    stack<pair<ll,ll>> s;
    ll ans=0;
    for(int i=0;i<n;i++){
        int start=i;
        while(!s.empty()&&v[i]<=s.top().second){
            pair<ll,ll> curr=s.top();
            s.pop();
            start=curr.first;
            ans=max(ans,((i-start)*curr.second));
        }
        s.push({start,v[i]});
    }
    while(!s.empty()){
        pair<ll,ll> curr=s.top();
        s.pop();
        ans=max(ans,((n-curr.first)*curr.second));
    }
    cout << ans << '\n';
}       