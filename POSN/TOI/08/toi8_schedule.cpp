#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
pair<int,int> dp[N][N];
int a1[N],a2[N];

int main(){
    int m,n;
    cin >> m >> n;
    for(int i=1;i<=n;i++){
        cin >> a1[i];
    }
    for(int i=1;i<=n;i++){
        cin >> a2[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]={2e9,2e9};
        }
    }
    dp[0][0]={0,0};
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0&&j==0)continue;
            if(j){
                int day=dp[i][j-1].first;
                int t=dp[i][j-1].second;
                if(t+a2[j]<=m)t+=a2[j];
                else{
                    day++;
                    t=a2[j];
                }
                if(day<dp[i][j].first){
                    dp[i][j]={day,t};
                }
                else if(day==dp[i][j].first){
                    dp[i][j].second=min(dp[i][j].second,t);
                }
                if(i==1&&j==3){
                    // cout << day << ' ' << t << ' ' << a2[j] << dp[i][j].first << ' ' << dp[i][j].second;
                }
            }
            if(i){
                int day=dp[i-1][j].first;
                int t=dp[i-1][j].second;
                if(t+a1[i]<=m)t+=a1[i];
                else{
                    day++;
                    t=a1[i];
                }
                if(day<dp[i][j].first){
                    dp[i][j]={day,t};
                }
                else if(day==dp[i][j].first){
                    dp[i][j].second=min(dp[i][j].second,t);
                }
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout << i << j << ' ' << dp[i][j].first << ' ' << dp[i][j].second << '\n';
        }
    }
    // cout << dp[n][n].first+1 << '\n' << dp[n][n].second;
}