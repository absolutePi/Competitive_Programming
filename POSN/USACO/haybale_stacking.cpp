#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n+1,0);
    for(int i=0;i<k;i++){
        int l,r;
        cin >> l >> r;
        v[l]++;
        v[r+1]--;
    }
    int prefix = 0;
    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        prefix+=v[i];
        ans[i]=prefix;
    }
    sort(ans.begin(),ans.end());
    cout << ans[n/2];
}