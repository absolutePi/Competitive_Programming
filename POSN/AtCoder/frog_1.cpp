#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    vector<int> heights(n);
    for(auto &i : heights){cin >> i;}
    vector<int> dp(n,INT_MAX);
    dp[0]=0;
    for(int i=0;i<n-1;i++){
        dp[i+1]=min(dp[i+1],dp[i]+abs(heights[i]-heights[i+1]));
        if(i+2<n){
            dp[i+2]=min(dp[i+2],dp[i]+abs(heights[i]-heights[i+2]));
        }
    }
    cout << dp[n-1];
}