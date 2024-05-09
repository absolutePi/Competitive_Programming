#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int prf[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        x++;y++;//shifting border to 1-indexed
        prf[x][y]++;
    }
    // cout << "D";
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            prf[i][j]=prf[i][j]+prf[i][j-1];
        }
    }
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            prf[i][j]=prf[i][j]+prf[i-1][j];
        }
    }
    // cout << "E";
    for(int i=0;i<m;i++){
        int x,y,k;
        cin >> x >> y >> k;
        x++;y++;
        int ans=prf[min(x+k,1001)][min(y+k,1001)]-prf[max(0,x-k-1)][min(y+k,1001)]-prf[min(x+k,1001)][max(0,y-k-1)]+prf[max(0,x-k-1)][max(0,y-k-1)];
        cout << ans << '\n';
    }
//    cout << "F";
}