#include <bits/stdc++.h>

using namespace std;

int n,k;
const int MAX_ROWS = 100;
const int MAX_COLS = 10;
vector<vector<char>> board(MAX_ROWS,vector<char>(MAX_COLS));
vector<vector<bool>> visited(MAX_ROWS,vector<bool>(MAX_COLS));
vector<pair<int,int>> comps;

int floodfill(int i,int j,char color){
    int cnt=1;
    if(i<0||i>=n||j<0||j>=MAX_COLS||visited[i][j]||board[i][j]!=color){
        return 0;
    }
    visited[i][j]=true;
    comps.push_back({i,j});
    cnt+=floodfill(i+1,j,color)+floodfill(i,j+1,color)+floodfill(i,j-1,color)+floodfill(i-1,j,color);
    return cnt;
}

int main(){
    freopen("mooyomooyo.in","r",stdin);
    freopen("mooyomooyo.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> k;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<MAX_COLS;j++){
            cin >> board[i][j];
        }
    }
    bool board_change=true;
    while(board_change){
        board_change=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<MAX_COLS;j++){
                if(!visited[i][j]&&board[i][j]!='0'){
                    char curr_color=board[i][j];
                    int cnt=floodfill(i,j,curr_color);
                    if(cnt>=k){
                        board_change=true;
                        for(auto i : comps){
                            board[i.first][i.second]='0';
                        }
                    }
                    comps.clear();
                }
                
            }
        }
        for(int j=0;j<MAX_COLS;j++){
            vector<char> after;
            for(int i=0;i<n;i++){
                if(board[i][j]!='0'){
                    after.push_back(board[i][j]);
                }
            }
            for(int i=0;i<n;i++){
                if(i<after.size()){
                    board[i][j]=after[i];
                }
                else{
                    board[i][j]='0';
                }
            }
        }
        fill(visited.begin(),visited.end(),vector<bool>(MAX_COLS,false));
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<MAX_COLS;j++){
            cout << board[i][j];
        }
        cout << endl;
    }
}