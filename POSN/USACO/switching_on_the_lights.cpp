#include <bits/stdc++.h>

using namespace std;

int n,m;
const int N = 101;
bool visited[N][N];
bool lit[N][N];
vector<pair<int,int>> switches[N][N];
int LitRooms=1;
int rowMovements[] = {1,0,-1,0};
int colMovements[] = {0,1,0,-1};

bool check(int r,int c){
    for(int i=0;i<4;i++){
        int newRow = r+rowMovements[i];
        int newCol = c+colMovements[i];
        if(newRow<0||newRow>=n||newCol<0||newCol>=n){continue;}
        if(visited[newRow][newCol]){
            return true;
        }
    }
    return false;
}

void floodfill(int r,int c){
    if(visited[r][c]||!lit[r][c]||r<0||r>=n||c<0||c>=n){return;}
    if(!check(r,c)&&!(r==0&&c==0)){
        //if check return false=not connected to the main components
        return;
    }
    visited[r][c]=true;
    for(int i=0;i<switches[r][c].size();i++){
        int x = switches[r][c][i].first;
        int y = switches[r][c][i].second;
        if(!lit[x][y]){
            LitRooms++;
            lit[x][y]=true;
        }
        floodfill(x,y);
    }
    for(int i=0;i<4;i++){
        floodfill(r+rowMovements[i],c+colMovements[i]);
    }
    return;
    
}

int main(){
    freopen("lightson.in","r",stdin);
    freopen("lightson.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        switches[a-1][b-1].push_back({c-1,d-1});
    }
    lit[0][0]=true;
    floodfill(0,0);
    cout << LitRooms << endl;
}