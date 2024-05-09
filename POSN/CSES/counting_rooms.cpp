#include <bits/stdc++.h>

using namespace std;

const int N = 1001;

int n,m;
char grid[N][N];
bool visited[N][N];

void floodfill(int r,int c){
    if(visited[r][c]||grid[r][c]!='.'){return;}
    if(r<0||r>=n||c<0||c>=m){return;}
    visited[r][c]=true;
    floodfill(r+1,c);
    floodfill(r-1,c);
    floodfill(r,c+1);
    floodfill(r,c-1);
    return;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int comps=0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]&&grid[i][j]=='.'){
                comps++;
                floodfill(i,j);
            }
        }
    }
    cout << comps;
}   