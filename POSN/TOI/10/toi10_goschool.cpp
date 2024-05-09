#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 55;
int grid[N][N];
bool dog[N][N],vis[N][N];
int n,m;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int a,b;
        cin >> b >> a;
        dog[a][b]=true;
    }
    grid[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(dog[i][j])continue;
            if(i>=2)grid[i][j]+=grid[i-1][j];
            if(j>=2)grid[i][j]+=grid[i][j-1];
        }
    }
    cout << grid[n][m] << '\n';
}       
