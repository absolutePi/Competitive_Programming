#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>> elevation;
vector<vector<int>> waypoints;

vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};

void floodfill(int r,int c,int range,vector<vector<bool>> &visited){
    if(visited[r][c]){return;}
    visited[r][c]=true;
    for(auto i : dirs){
        int newr = r+i.first;
        int newc = c+i.second;
        if(newr>=0&&newr<n&&newc>=0&&newc<m){
            if(abs(elevation[r][c]-elevation[newr][newc])<=range){
                floodfill(newr,newc,range,visited);
            }
        }
    }
    return;
}

bool check(int mid){
    vector<vector<bool>> visited(n,vector<bool>(m));
    bool found = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(waypoints[i][j]==1){
                found=true;
                floodfill(i,j,mid,visited);
                break;
            }
        }
        if(found){
            break;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(waypoints[i][j]==1&&!visited[i][j]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    freopen("ccski.in","r",stdin);
    freopen("ccski.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> m;
    elevation = waypoints = vector<vector<int>>(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> elevation[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> waypoints[i][j];
        }
    }
    int l=0,r=1e9,mid,ans;
    while(l<r){
        mid = l+(r-l)/2;
        if(check(mid)){
            r=mid;
            ans=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout << ans;
}