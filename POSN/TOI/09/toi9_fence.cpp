#include <bits/stdc++.h>

using namespace std;

const int N = 505;
int ver_prf[N][N],hor_prf[N][N];

void solve(){
    int n,m;
    cin >> n >> m;
    int mx=max(n,m);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            ver_prf[i][j]=0;
            hor_prf[i][j]=0;
        }
    }
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int x,y;
        cin >> x >> y;
        x++;y++;//0->1 indexed
        hor_prf[x][y]=1;
        ver_prf[x][y]=1;
    }
    //horizontal
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            hor_prf[i][j]+=hor_prf[i][j-1];
        }
    }
    //vertical
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            ver_prf[i][j]+=ver_prf[i-1][j];
        }
    }
    for(int sz=mx;sz>=2;sz--){
        for(int i=sz;i<=n;i++){
            for(int j=sz;j<=m;j++){
                int sum=0;
                sum+=hor_prf[i][j]-hor_prf[i][j-sz];
                sum+=hor_prf[i-sz+1][j]-hor_prf[i-sz+1][j-sz];
                sum+=ver_prf[i-1][j]-ver_prf[i-sz+1][j];
                sum+=ver_prf[i-1][j-sz+1]-ver_prf[i-sz+1][j-sz+1];
                if(sum==0){
                    cout << sz << '\n';
                    return;
                }
            }
        }
    }
    cout << 1 << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<2;i++){
        solve();
    }
}