#include <bits/stdc++.h>

using namespace std;

const int N = 200;
int grid[N][N];
int mx[]={1,-1,0,0},my[]={0,0,1,-1};
int n,m,a,b,cnt=0;
bool vis[N][N];
int dist[N][N];
// vector<pair<int,int>> v;

bool within(int x,int y){
    return (x>=0&&y>=0&&x<n&&y<m);
}

void dfs1(int x,int y){
    grid[x][y]=2;
    for(int i=0;i<4;i++){
        int newx=x+mx[i];
        int newy=y+my[i];
        if(within(newx,newy)&&grid[newx][newy]==1){
            dfs1(newx,newy);
        }
    }
}

void dfs2(int x,int y){
    if(vis[x][y])return;
    vis[x][y]=true;
    for(int i=0;i<4;i++){//check for walls that might be connected to the target's component
        int newx=x+mx[i];
        int newy=y+my[i];
        if(within(newx,newy)&&grid[newx][newy]==0){
            for(int j=0;j<4;j++){
                int new_newx=newx+mx[j];
                int new_newy=newy+my[j];
                if(within(new_newx,new_newy)&&grid[new_newx][new_newy]==2){
                    grid[newx][newy]=3;//break the wall
                    cnt++;
                    // v.push_back({newx,newy});
                    break;
                }
            }
        }
    }
    for(int i=0;i<4;i++){
        int newx=x+mx[i];
        int newy=y+my[i];
        if(within(newx,newy)&&grid[newx][newy]==1&&!vis[newx][newy])dfs2(newx,newy);
    }
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    pair<int,int> start,target;
    cin >> a >> b;
    a--;b--;
    start={a,b};
    cin >> a >> b;
    a--;b--;
    target={a,b};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    // cout << a << ' ' << b << '\n';
    dfs1(a,b);
    dfs2(start.first,start.second);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << grid[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    queue<pair<int,int>> q;
    q.push({start.first,start.second});
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j]=2e9;
        }
    }
    dist[start.first][start.second]=1;
    while(!q.empty()){
        int x,y;
        tie(x,y)=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int newx=x+mx[i];
            int newy=y+my[i];
            if(within(newx,newy)&&grid[newx][newy]){
                if(dist[x][y]+1<dist[newx][newy]){
                    dist[newx][newy]=dist[x][y]+1;
                    q.push({newx,newy});
                }
            }
        }
    }
    cout << cnt << '\n' << dist[target.first][target.second];
    // for(auto i : v){
    //     cout << i.first << ' ' << i.second << '\n';
    // }
}