#include <bits/stdc++.h>

using namespace std;

const int N = 100;
int grid[N][N];
bool vis[N][N];
int mx[]={1,-1,0,0},my[]={0,0,1,-1};
int n;
int curr,cnt;

bool within(int x,int y){
    return (x>=50&&y>=50&&(x<n+50)&&(y<n+50));
}

int dfs(int x,int y){
    if(vis[x][y])return 0;
    vis[x][y]=true;
    cnt++;
    for(int i=0;i<4;i++){
        int newx=x+mx[i];
        int newy=y+my[i];
        if(within(newx,newy)&&grid[newx][newy]==curr){
            dfs(newx,newy);
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=50;i<n+50;i++){
        for(int j=50;j<n+50;j++){
            cin >> grid[i][j];
        }
    }
    int ans=0;
    for(int i=50;i<n+50;i++){
        for(int j=50;j<n+50;j++){
            if(grid[i][j]!=0&&!vis[i][j]){
                curr=grid[i][j];
                cnt=0;
                if(dfs(i,j)==3){
                    if(grid[i+1][j]==curr && grid[i][j+1]==curr)ans++;
                    else if(grid[i+1][j]==curr && grid[i+1][j-1]==curr)ans++;
                    else if(grid[i][j+1]==curr && grid[i+1][j+1]==curr)ans++;
                    else if(grid[i+1][j]==curr && grid[i+1][j+1]==curr)ans++;
                }
            }   
        }
    }
    cout << ans << '\n';
}