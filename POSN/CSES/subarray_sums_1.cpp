#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> v(n);
    for(auto &i : v){cin >> i;}

    int sum=0;
    int r=0;
    int ans=0;
    for(int i=0;i<n;i++){
        while(r<n && sum+v[r]<=x){
            sum+=v[r];
            r++;
            if(sum==x)ans++;
        }
        sum-=v[i];
    }
    cout << ans;
}