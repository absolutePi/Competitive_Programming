#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i : v){cin >> i;}
    multiset<int> s;
    for(int i=0;i<n;i++){
        auto it=s.upper_bound(v[i]);
        if(it==s.end()){
            s.insert(v[i]);
        }
        else{
            s.erase(it);
            s.insert(v[i]);
        }
    }
    int sz=s.size();
    cout << n-sz << '\n';
}