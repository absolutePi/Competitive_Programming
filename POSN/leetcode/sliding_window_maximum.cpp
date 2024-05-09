#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &i: v){cin >> i;}
    multiset<int> s;
    for(int i=0;i<k;i++){
        s.insert(v[i]);
    }
    vector<int> ans;
    for(int i=k;i<n;i++){
        ans.push_back(*s.rbegin());
        s.erase(s.find(v[i-k]));
        s.insert(v[i]);
    }
    ans.push_back(*s.rbegin());
    for(auto i : ans){
        cout << i << ' ';
    }
}