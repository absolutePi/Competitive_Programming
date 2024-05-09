#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+5;
int dp[N];

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,c;
    cin >> n >> c;
    int cnt=0,mx=0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x==c){
            cnt++;
        }
        else{
            dp[x]=max(dp[x],cnt)+1;
            mx=max(mx,dp[x]-cnt);
        }
    }
    cout << mx+cnt << '\n';
}