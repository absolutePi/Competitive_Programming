#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+5;
int dp[N];
pair<int,int> rooms[]={{1,500},{2,800},{5,1500},{15,3000}};

int main(){
    int n;
    cin >> n;
    for(int i=0;i<N;i++){
        dp[i]=2e9;
    }
    dp[0]=0;
    for(int i=0;i<=n+20;i++){
        for(int j=0;j<4;j++){
            int cap=rooms[j].first;
            int price=rooms[j].second;
            dp[i+cap]=min(dp[i+cap],dp[i]+price);
        }
    }
    int mn=INT_MAX;
    for(int i=n+20;i>=n;i--){
        if(dp[i]!=0)mn=min(mn,dp[i]);
        // cout << dp[i] << ' ';
    }
    cout << mn << '\n';
}