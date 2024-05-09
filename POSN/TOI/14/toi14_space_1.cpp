#include <bits/stdc++.h>

using namespace std;

bitset<2005> grid[10005];
int n,m,mxx,mnx,mxy,mny,area;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int star=0,planet=0,comet=0;

bool within(int x,int y){
    return (x>=0&&y>=0&&x<n&&y<m);
}

void bfs(int i,int j){
    mxx=i,mnx=i,mxy=j,mny=j,area=0;
    queue<pair<int,int>> q;
    q.push({i,j});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(grid[x][y]==0){continue;}
        mxx=max(mxx,x);
        mnx=min(mnx,x);
        mxy=max(mxy,y);
        mny=min(mny,y);
        grid[x][y]=0;
        area++;
        for(int k=0;k<4;k++){
            int newx=x+dx[k];
            int newy=y+dy[k];
            if(within(newx,newy)&&grid[newx][newy]==1){
                q.push({newx,newy});
            }
        }
    }
    if((mxx-mnx)==(mxy-mny)){
        if((mxx-mnx+1)*(mxy-mny+1)==area){
            planet++;
        }
        else{
            star++;
        }
    }
    else{
        comet++;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;//m=width n=height
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin >> c;
            if(c=='1'){
                grid[i][j]=1;
            }
            else{
                grid[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                bfs(i,j);
            }
        }
    }
    cout << planet << ' ' << star << ' ' << comet << '\n';
}