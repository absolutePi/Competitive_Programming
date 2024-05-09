#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+5;
int a[N],dp[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        dp[i]=max(0,a[i]-a[i-1])+dp[i-1];
    }
    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        cout << dp[b]-dp[a] << '\n';
    }
}