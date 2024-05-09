#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(auto &i : v){cin >> i.first >> i.second;}
    sort(v.begin(),v.end(),greater<pair<int,int>>());
    set<int> s;
    int lis=0;
    for(int i=0;i<n;i++){
        if(s.upper_bound(v[i].second)==s.end()){
            lis++;
        }
        else{
            s.erase(s.upper_bound(v[i].second));
        }
        s.insert(v[i].second);
    }
    cout << lis << '\n';
}