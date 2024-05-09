#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5+1;
int dp[N],arr[3];
 
int main(){
    int n;
    cin >> n;
    for(int i=0;i<3;i++){
        cin >> arr[i];
        dp[arr[i]] = 1;
    }
    for(int i=1;i<=n;i++){
        if(dp[i]){
            for(int j=0;j<3;j++){
                if(i+arr[j]<=n){
                    dp[i+arr[j]] = max(dp[i+arr[j]],dp[i]+1);
                }
            }
        }
    }
    cout << dp[n];
}