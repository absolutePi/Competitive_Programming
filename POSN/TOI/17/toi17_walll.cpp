#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int grid[N][N];//0=plain 1=house 2=water
bool vis[N][N];
int n,m,sum;
int mx[]={1,-1,0,0},my[]={0,0,1,-1};

bool within(int x,int y){
    return (x>=0&&y>=0&&x<n&&y<m);
}

void water_dfs(int x,int y){
    grid[x][y]=2;
    for(int i=0;i<4;i++){
        int newx=x+mx[i];
        int newy=y+my[i];
        if(within(newx,newy)&&grid[newx][newy]==0){
            water_dfs(newx,newy);
        }
    }
}

void dfs(int x,int y){
    vis[x][y]=true;
    for(int i=0;i<4;i++){
        int newx=x+mx[i];
        int newy=y+my[i];
        if(vis[newx][newy]){continue;}
        if(within(newx,newy)){
            if(grid[newx][newy]==2){
                sum++;
            }
            else if(grid[newx][newy]==1){
                dfs(newx,newy);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin >> c;
            if(c=='.'){
                grid[i][j]=0;
            }
            else if(c=='X'){
                grid[i][j]=1;
            }
        }
    }
    //water flooding
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0||j==0||i==n-1||j==m-1){
                if(grid[i][j]==0){
                    water_dfs(i,j);
                }
            }
        }
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1&&!vis[i][j]){
                sum=0;
                dfs(i,j);
                ans=max(ans,sum);
            }
        }
    }
    cout << ans << '\n';
}