#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=0;i<n-1;i++){
        v[i+1] = max(v[i+1],v[i]-m);
    }
    for(int i=n-1;i>0;i--){
        v[i-1] = max(v[i-1],v[i]-m);
    }
    for(auto i : v){
        cout << i << " ";
    }
}