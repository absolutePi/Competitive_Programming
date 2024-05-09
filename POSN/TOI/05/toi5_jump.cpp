#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &i : v){cin >> i;}
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        int it=upper_bound(v.begin(),v.end(),v[i]+k)-v.begin();
        it--;
        ans=max(ans,it-i);
    }
    cout << ans << '\n';
}