#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
const int INF = 2e9;
int a[N],dp[N];

int main(){
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        dp[i]=INF;
    }
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=1;i<n;i++){
        if(i)dp[i]=min(dp[i],dp[i-1]+abs(a[i-1]-a[i]));
        if(i-2>=0)dp[i]=min(dp[i],dp[i-2]+abs(a[i-2]-a[i]));
    }
    cout << dp[n-1] << '\n';
}