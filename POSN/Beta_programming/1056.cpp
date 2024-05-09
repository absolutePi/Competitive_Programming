#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &i : v)cin >> i;
    sort(v.begin(),v.end(),greater<int>());
    int ans=0,ind=0;
    while(ind<n){
        ans+=v[ind];
        ind+=k;
    }
    cout << ans << '\n';
}   