#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int prf[N][N];

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> prf[i][j];
            prf[i][j]+=prf[i][j-1];
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            prf[i][j]+=prf[i-1][j];
        }
    }
    int ans=INT_MIN;
    for(int i=k;i<=n;i++){
        for(int j=k;j<=m;j++){
            ans=max(ans,prf[i][j]-prf[i-k][j]-prf[i][j-k]+prf[i-k][j-k]);
        }
    }
    cout << ans << '\n';
}       