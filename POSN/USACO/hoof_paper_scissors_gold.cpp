#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int dp[N][25][3];
int fj[N];

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        char c;
        cin >> c;
        if(c=='H'){fj[i]=0;}
        if(c=='P'){fj[i]=1;}
        if(c=='S'){fj[i]=2;}
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            for(int c=0;c<3;c++){
                if(c==fj[i])dp[i][j][c]++;
                dp[i+1][j+1][0]=max(dp[i+1][j+1][0],dp[i][j][c]);
                dp[i+1][j+1][1]=max(dp[i+1][j+1][1],dp[i][j][c]);
                dp[i+1][j+1][2]=max(dp[i+1][j+1][2],dp[i][j][c]);
                dp[i+1][j][c]=max(dp[i+1][j][c],dp[i][j][c]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<3;i++){
        ans=max(ans,dp[n-1][k][i]);
    }
    cout << ans << '\n';
}