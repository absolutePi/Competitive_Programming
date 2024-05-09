#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 3005;
int a[N];
int dp[N][N];

int best(int l,int r){
    if(l==r)return a[l];
    if(dp[l][r])return dp[l][r];
    int b1=a[l]-best(l+1,r);
    int b2=a[r]-best(l,r-1);
    return dp[l][r]=max(b1,b2);
}

signed main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    cout << best(1,n);
}