#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    freopen("pairup.in","r",stdin);
    freopen("pairup.out","w",stdout);
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    //first = cow_milking_time, second = amount
    for(pair<int,int> &a : v){
        cin >> a.second >> a.first;
    }
    sort(v.begin(),v.end());

    int l=0;
    int r=n-1;
    int mx=0;
    int paired=0;
    while(l<r){
        mx = max(mx,v[l].first+v[r].first);
        paired = min(v[l].second,v[r].second);
        v[l].second-=paired;
        v[r].second-=paired;
        if(v[l].second==0)l++;
        if(v[r].second==0)r--;
    }
    cout << mx;
}