#include <bits/stdc++.h>

using namespace std;

const int K = 8;
const int N = 1e4+5;
int dp[(1<<K)];
pair<int,int> a[N];

int main(){
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int price;
        cin >> price;
        int bit=0;
        for(int j=0;j<k;j++){
            int x;
            cin >> x;
            bit=(bit<<1)+x;
        }
        a[i]={price,bit};
    }
    for(int i=0;i<(1<<k);i++)dp[i]=2e9;
    dp[0]=0;
    for(int s=0;s<(1<<k);s++){
        for(int i=0;i<n;i++){
            dp[s|a[i].second]=min(dp[s|a[i].second],dp[s]+a[i].first);
        }
    }
    cout << dp[(1<<k)-1];
    // for(int i=0;i<(1<<k);i++){
    //     cout << dp[i] << ' ';
    // }
}