#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i : v){cin >> i;}
    multiset<int> s;
    int ans=0;
    for(int i=0;i<n;i++){
        if(s.upper_bound(v[i])==s.end()){
            ans++;
        }
        else{
            s.erase(s.upper_bound(v[i]));
        }
        s.insert(v[i]);
    }
    cout << ans << '\n';
}