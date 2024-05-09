#include <bits/stdc++.h>

using namespace std;

const int N = 51;
int n,m;
char grid[N][N];
int row[]={1,0,-1,0};
int col[]={0,1,0,-1};
bool visited[N][N];

void floodfill(int r,int c){
    if(visited[r][c]){return;}
    if(r<0||r>=n||c<0||c>=m){return;}
    if(grid[r][c]=='#'){return;}
    visited[r][c]=true;
    floodfill(r+1,c);
    floodfill(r-1,c);
    floodfill(r,c+1);
    floodfill(r,c-1);
    return;
}

void solve(){
    memset(visited,0,sizeof(visited));
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='B'){
                for(int x=0;x<4;x++){
                    int newrow = i+row[x];
                    int newcol = j+col[x];
                    if(newrow>=0&&newrow<n&&newcol>=0&&newcol<m){
                        if(grid[newrow][newcol]=='G'){
                            cout << "No\n";
                            return;
                        }
                        if(grid[newrow][newcol]=='.'){
                            grid[newrow][newcol]='#';
                        }
                    }
                }
            }
        }
    }
    floodfill(n-1,m-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='G'&&!visited[i][j]){
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
}