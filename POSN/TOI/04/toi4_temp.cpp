#include <bits/stdc++.h>

using namespace std;

const int N = 30;
int grid[N][N];
bool vis[N][N];
int mx[]={1,-1,0,0},my[]={0,0,1,-1};
int n;

bool within(int x,int y){
    return (x>=1&&y>=1&&x<=n&&y<=n);
}

int main(){
    cin >> n;
    pair<int,int> start;
    cin >> start.second >> start.first;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> grid[i][j];
        }
    }
    queue<pair<int,int>> q;
    q.push(start);
    int ans=INT_MIN;
    while(!q.empty()){
        int x,y;
        tie(x,y)=q.front();
        q.pop();
        if(vis[x][y])continue;
        vis[x][y]=true;
        ans=max(ans,grid[x][y]);
        for(int i=0;i<4;i++){
            int newx=x+mx[i];
            int newy=y+my[i];
            if(within(newx,newy)&&grid[newx][newy]!=100&&grid[newx][newy]>grid[x][y]){
                q.push({newx,newy});
            }
        }
    }
    cout << ans << '\n';
}