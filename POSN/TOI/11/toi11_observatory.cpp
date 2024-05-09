#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
int grid[N][N];
int prf[N][N];
int vs[N][N];//vertical sum
int hs[N][N];//horizontal sum
int ans=INT_MIN;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    /*
   .
   ..
   ...
   */
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            prf[i][j]=grid[i][j];
            if(i!=0&&j!=0){
                prf[i][j]+=prf[i-1][j-1];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vs[i][j]=prf[i][j];
            if(i!=0){
                vs[i][j]+=vs[i-1][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            hs[i][j]=prf[i][j];
            if(j!=0){
                hs[i][j]+=hs[i][j-1];
            }
        }
    }
    for(int i=k-1;i<n;i++){
        for(int j=0;j<=m-k;j++){
            int hori,verti;
            hori=hs[i][j+k-1];
            if(j!=0){
                hori-=hs[i][j-1];
            }
            verti=0;
            if(j!=0&&i!=0){
                verti=vs[i-1][j-1];
                if((i-k)>0){
                    verti-=vs[i-k-1][j-1];
                }
            }
            int curr_ans=hori-verti;
            ans=max(ans,curr_ans);
        }
    }
    /*
      .
     ..
    ...
    */
   memset(vs,0,sizeof(vs));
   memset(hs,0,sizeof(hs));
   for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            prf[i][j]=grid[i][j];
            if(i!=0&&j!=m-1){
                prf[i][j]+=prf[i-1][j+1];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vs[i][j]=prf[i][j];
            if(i!=0){
                vs[i][j]+=vs[i-1][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            hs[i][j]=prf[i][j];
            if(j!=0){
                hs[i][j]+=hs[i][j-1];
            }
        }
    }
    for(int i=k-1;i<n;i++){
        for(int j=k-1;j<m;j++){
            int hori,verti;
            hori=hs[i][j];
            if((j-k)>=0){
                hori-=hs[i][j-k];
            }
            verti=0;
            if((j!=m-1)&&i!=0){
                verti=vs[i-1][j+1];
                if((i-k)>0){
                    verti-=vs[i-k-1][j+1];
                }
            }
            int curr_ans=hori-verti;
            ans=max(ans,curr_ans);
        }
    }
    cout << ans << '\n';
}   