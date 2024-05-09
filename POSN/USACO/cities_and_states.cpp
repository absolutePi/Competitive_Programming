#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    freopen("citystate.in","r",stdin);
    freopen("citystate.out","w",stdout);
    int n;
    ll total=0;
    cin >> n;
    vector<pair<string,string>> pairs;
    for(int i=0;i<n;i++){
        string city,state;
        cin >> city >> state;
        city = city.substr(0,2);
        pairs.emplace_back(city,state);
    }
    map<string,int> seen;
    for(auto &[c,s] : pairs){
        if(c!=s){
            total += seen[s+c];
        }
        seen[c+s]++;
    }
    cout << total;
}