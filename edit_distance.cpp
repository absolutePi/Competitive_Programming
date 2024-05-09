#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    string str1,str2;
    cin >> str1 >> str2;
    int l1=str1.length(),l2=str2.length();
    vector<vector<int>> dp(l1+1,vector<int>(l2+1,INT_MAX));
    dp[0][0]=0;
    for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){
            if(i!=0){
                dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
            }
            if(j!=0){
                dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
            }
            if(i!=0 && j!=0){
                int new_cost = dp[i-1][j-1]+(str1[i-1]!=str2[j-1]);
                dp[i][j]=min(dp[i][j],new_cost);
            }
        }
    }
    cout << dp[l1][l2] << '\n';
}   