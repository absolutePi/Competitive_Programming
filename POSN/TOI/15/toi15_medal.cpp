#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n; 
    vector<int> v1(n),v2(n),v(n);
    for(auto &i : v1){cin >> i;}
    for(auto &i : v2){cin >> i;}
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end(),greater<int>());
    for(int i=0;i<n;i++){
        v[i]=v1[i]+v2[i];
    }
    sort(v.begin(),v.end());
    cout << v[n-1]-v[0] << '\n';
}   