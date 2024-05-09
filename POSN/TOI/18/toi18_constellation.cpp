#include <bits/stdc++.h>

using namespace std;

const int N = 1505;
const int MOD = 1000003;

int n,m,k,ans,dist1[N][N],dist2[N][N];//dist1 top right to bottom left
                                //dist2 top left to bottom right
int pascal[N][N];

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin >> c;
            dist1[i+600][j+600]=(c=='#');
            dist2[i+600][j+600]=(c=='#');
        }
    }
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            dist1[i][j]+=dist1[i-1][j+1];
            dist2[i][j]+=dist2[i-1][j-1];
        }
    }
    for(int i=1;i<N;i++){
        pascal[i][0]=pascal[i][i]=1;
        for(int j=1;j<i;j++){
            pascal[i][j]=(pascal[i-1][j]+pascal[i-1][j-1])%MOD;
        }
    }
    for(int l=1;l<=n+m;l++){
        for(int i=601;i<=n+600;i++){
            for(int j=601;j<=m+600;j++){
                int cnt=0;
                cnt+=dist1[i][j-l]-dist1[i-l-1][j+1];
                cnt+=dist1[i+l][j]-dist1[i-1][j+l+1];
                cnt+=dist2[i-1][j+l-1]-dist2[i-l][j];
                cnt+=dist2[i+l-1][j-1]-dist2[i][j-l];
                if(cnt>=k){
                    ans=(ans+pascal[cnt][k])%MOD;
                }
            }
        }
    }
    cout << ans << '\n';
}