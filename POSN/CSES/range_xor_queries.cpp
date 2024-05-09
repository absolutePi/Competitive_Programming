#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    for(auto &i : v){cin >> i;}
    vector<int> prefix(n+1,0);
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]^v[i-1];
    }
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        cout << (prefix[r]^prefix[l-1]) << endl;
    }
}