#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int n,t;
    cin >> n >> t;
    vector<int> v(n);
    for(auto &i : v){cin >> i;}

    int r=0;
    int sum=0;
    int ans=0;
    for(int i=0;i<n;i++){
        while(r<n && sum+v[r]<=t){
            sum+=v[r];
            r++;
        }
        ans = max(ans,r-i);
        sum-=v[i];
    }
    cout << ans;
}