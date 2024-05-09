#include <bits/stdc++.h>

using namespace std;

#define f first 
#define s second 

const int MX = 1005;
int dp[MX][MX];

int main(){
    freopen("radio.in","r",stdin);
    freopen("radio.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> fj(n+1);
    vector<pair<int,int>> b(m+1);
    int currfjx,currfjy;
    cin >> currfjx >> currfjy;
    int currbx,currby;
    cin >> currbx >> currby;
    fj[0]={currfjx, currfjy};
    for(int i=1;i<=n;i++){
        char c;
        cin >> c;
        if(c=='N'){
            currfjy++;
        }
        else if(c=='S'){
            currfjy--;
        }
        else if(c=='E'){
            currfjx++;
        }
        else if(c=='W'){
            currfjx--;
        }
        fj[i].f=currfjx;
        fj[i].s=currfjy;
    }
    b[0]={currbx, currby};
    for(int i=1;i<=m;i++){
        char c;
        cin >> c;
        if(c=='N'){
            currby++;
        }
        if(c=='S'){
            currby--;
        }
        if(c=='E'){
            currbx++;
        }
        if(c=='W'){
            currbx--;
        }
        b[i].f=currbx;
        b[i].s=currby;
    }
    dp[0][0]=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i!=0||j!=0){
                dp[i][j]=INT_MAX;
                if(i!=0){
                    dp[i][j]=min(dp[i][j],dp[i-1][j]);
                }
                if(j!=0){
                    dp[i][j]=min(dp[i][j],dp[i][j-1]);
                }
                if(i!=0 && j!=0){
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                }
                int cost = abs(fj[i].f-b[j].f)*abs(fj[i].f-b[j].f)+abs(fj[i].s-b[j].s)*abs(fj[i].s-b[j].s);
                dp[i][j]+=cost;
            }
        }
    }
    cout << dp[n][m];
}