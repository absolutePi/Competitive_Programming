#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i : v){cin >> i;}
    vector<int> dp;
    for(auto i : v){
        int pos=lower_bound(dp.begin(),dp.end(),i)-dp.begin();
        if(pos==dp.size()){
            dp.push_back(i);
        }
        else{
            dp[pos]=i;
        }
    }
    cout << dp.size();
}