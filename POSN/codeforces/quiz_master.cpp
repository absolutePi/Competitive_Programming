#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for(auto &i : v){cin >> i;}
    sort(v.begin(),v.end());
    vector<vector<int>> factors(n);
    for(int i=0;i<n;i++){
        int element = v[i];
        for(int j=1;j*j<=element && j<=m;j++){
            if(element%j==0){
                factors[i].push_back(j);
                if(j!=element/j && element/j<=m){
                    factors[i].push_back(element/j);
                }
            }
        }
    }
    vector<int> target(m+1,0);
    int l=0;
    int cnt=0;
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        for(auto i : factors[i]){
            target[i]++;
            if(target[i]==1){
                cnt++;
            }
        }
        while(cnt==m){
            ans = min(ans,v[i]-v[l]);

            for(auto i : factors[l]){
                target[i]--;
                if(target[i]==0){
                    cnt--;
                }
            }
            l++;
        }
    }
    if(ans==INT_MAX)cout << "-1";
    else cout << ans;
    cout << endl;
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}