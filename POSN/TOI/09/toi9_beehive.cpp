#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
pair<int,int> dp[N][N];//honey ways
int grid[N][N];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    for(int j=0;j<m;j++){//initialize
        dp[0][j]={grid[0][j],1};
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(i%2){
                int mx=dp[i-1][j].first;
                if(j!=m-1)mx=max(mx,dp[i-1][j+1].first);
                dp[i][j].first=mx+grid[i][j];
                int curr_ways=0;
                if(dp[i-1][j].first==mx)curr_ways+=dp[i-1][j].second;
                if((j!=m-1)&&(dp[i-1][j+1].first==mx))curr_ways+=dp[i-1][j+1].second;
                dp[i][j].second=curr_ways;
            }
            else{
                int mx=dp[i-1][j].first;
                if(j)mx=max(mx,dp[i-1][j-1].first);
                dp[i][j].first=mx+grid[i][j];
                int curr_ways=0;
                if(dp[i-1][j].first==mx)curr_ways+=dp[i-1][j].second;
                if(j&&(dp[i-1][j-1].first==mx))curr_ways+=dp[i-1][j-1].second;
                dp[i][j].second=curr_ways;
            }
        }
    }
    int mx=INT_MIN;
    for(int j=0;j<m;j++){
        mx=max(mx,dp[n-1][j].first);
    }
    int ways=0;
    for(int j=0;j<m;j++){
        if(dp[n-1][j].first==mx)ways+=dp[n-1][j].second;
    }
    cout << mx << ' ' << ways << '\n';
}