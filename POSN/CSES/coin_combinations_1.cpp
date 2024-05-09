#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e9+7;
 
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,x;
    cin >> n >> x;
    vector<int> coin(n);
    for(auto &i : coin){cin >> i;}
    vector<int> dp(x+1);
    dp[0]=1;
    for(int i=0;i<x;i++){
        for(int j=0;j<n;j++){
            if(i+coin[j]<=x){
                dp[i+coin[j]]+=dp[i];
                dp[i+coin[j]]%=N;
            }
        }
    }
    cout << dp[x] << '\n';
}
