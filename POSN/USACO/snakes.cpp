#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    int n,k;
    cin >> n >> k;
    vector<int> groups(n+1);
    for(int i=1;i<=n;i++){
        cin >> groups[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    int largest_group=-1;
    int sum=0;
    for(int i=1;i<=n;i++){
        largest_group=max(largest_group,groups[i]);
        dp[i][0]=largest_group*i;
        for(int j=1;j<=k;j++){
            dp[i][j]=INT_MAX;
            int new_net=groups[i];
            for(int c=i-1;c>=0;c--){
                dp[i][j]=min(dp[i][j],dp[c][j-1]+new_net*(i-c));
                new_net=max(new_net,groups[c]);
            }
        }
        sum+=groups[i];
    }
    cout << dp[n][k]-sum << '\n';
}