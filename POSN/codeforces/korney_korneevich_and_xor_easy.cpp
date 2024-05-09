#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1<<9;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i : arr){cin >> i;}
    vector<vector<bool>> dp(MAXN,vector<bool>(MAXN));
    for(int i=0;i<MAXN;i++){dp[0][i]=true;}
    for(auto a : arr){
        if(a==0){continue;}
        for(int i=0;i<MAXN;i++){
            dp[a^i][a]=dp[a^i][a]||dp[i][a-1];
        }
    }
}