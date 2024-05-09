#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v1(n),v2(n);
    for(auto &i : v1){cin >> i;}
    for(auto &i : v2){cin >> i;}
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(v1[i]-v2[i]);
    }
    cout << ans << '\n';
}