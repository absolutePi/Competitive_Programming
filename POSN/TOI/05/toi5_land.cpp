#include <bits/stdc++.h>

using namespace std;

const int N = 5;
double grid[N][N];
int mx[]={-1,-1,0,1,1,1,0,-1},my[]={0,1,1,1,0,-1,-1,-1};
int n,m;
bool vis[N][N];

bool within(int x,int y){
    return (x>=0&&y>=0&&x<n&&y<m);
}

double recur(int x,int y){
    vis[x][y]=true;
    for(int i=0;i<8;i++){
        int newx=x+mx[i];
        int newy=y+my[i];
        if(within(newx,newy)){
            grid[newx][newy]+=(grid[x][y]*0.1);
        }
    }
    double curr_min=INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                curr_min=min(curr_min,recur(i,j));
            }
        }
    }
    if(curr_min==INT_MAX)curr_min=0;
    // cout << curr_min << '\n';
    vis[x][y]=false;
    for(int i=0;i<8;i++){
        int newx=x+mx[i];
        int newy=y+my[i];
        if(within(newx,newy)){
            grid[newx][newy]-=(grid[x][y]*0.1);
        }
    }
    return grid[x][y]+curr_min;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    double ans=INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans=min(ans,recur(i,j));
        }
    }
    cout << fixed << setprecision(2) << ans << '\n';
}

