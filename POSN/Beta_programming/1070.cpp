#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i : v)cin >> i;
    sort(v.begin(),v.end());
    if(v.size()<3)cout << "no";
    else if(v[0]+v[1]>v[n-1])cout << "no";
    else cout << "yes";
}