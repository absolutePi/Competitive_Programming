#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("teamwork.in","r",stdin);
    freopen("teamwork.out","w",stdout);
    int n,k;
    cin >> n >> k;
    vector<int> cows(n);
    for(auto &i : cows){cin >> i;}
    vector<int> dp(n,-1);
    for(int i=0;i<n;i++){
        int curr_max=cows[i];
        for(int j=i;j>=(i-k+1)&&j>=0;j--){
            curr_max=max(curr_max,cows[j]);
            if(j>0){
                dp[i]=max(dp[i],dp[j-1]+(curr_max*(i-j+1)));
            }
            else{
                dp[i]=max(dp[i],curr_max*(i-j+1));
            }
        }
    }   
    cout << dp[n-1] << '\n';
}