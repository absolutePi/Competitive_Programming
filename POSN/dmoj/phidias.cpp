#include <bits/stdc++.h>

using namespace std;

const int MAXN=600;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int w,h;
    cin >> w >> h;
    int n;
    cin >> n;
    vector<pair<int,int>> slabs(n);
    for(auto &[width,height] : slabs){
        cin >> width >> height;
    }
    vector<vector<int>> dp(MAXN+1,vector<int>(MAXN+1));
    for(int i=1;i<=w;i++){//i=width j=height
        for(int j=1;j<=h;j++){
            dp[i][j]=i*j;
        }
    }
    for(int i=0;i<n;i++){
        dp[slabs[i].first][slabs[i].second]=0;
    }
    for(int i=1;i<=w;i++){
        for(int j=1;j<=h;j++){
            for(int x=1;x<=i;x++){
                dp[i][j]=min(dp[i][j],dp[x][j]+dp[i-x][j]);
            }
            for(int y=1;y<=j;y++){
                dp[i][j]=min(dp[i][j],dp[i][y]+dp[i][j-y]);
            }
        }
    }
    cout << dp[w][h] << '\n';
}   