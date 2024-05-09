#include <bits/stdc++.h>

using namespace std;

const int N = 800;
int n,s;
int mx[]={1,-1,0,0},my[]={0,0,1,-1};
vector<vector<char>> grid(N,vector<char>(N));


bool valid_sit(int x,int y){
    return (x>=0&&y>=0&&x<n&&y<n&&(grid[x][y]=='G'||grid[x][y]=='M'));
}

bool mecho_reached(int m,int b){
    return (m/s)<b;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> s;
    vector<pair<int,int>> bees;
    pair<int,int> mecho,home;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
            if(grid[i][j]=='H'){
                bees.push_back({i,j});
            }
            if(grid[i][j]=='M'){
                mecho = {i,j};
            }
            if(grid[i][j]=='D'){
                home = {i,j};
            }
        }
    }
    int l=0,r=n*n;
    while(l<=r){
        vector<vector<bool>> visb(n,vector<bool>(n)),vism(n,vector<bool>(n));
        vector<vector<int>> distb(n,vector<int>(n)),distm(n,vector<int>(n));    
        queue<pair<int,int>> q;
        int eating_time=l+(r-l)/2;
        for(auto i : bees){
            q.push(i);
            visb[i.first][i.second]=true;
        }
        while(!q.empty()){
            int x,y;
            tie(x,y)=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int newx=x+mx[i];
                int newy=y+my[i];
                if(valid_sit(newx,newy)&&!visb[newx][newy]){
                    distb[newx][newy]=distb[x][y]+1;
                    q.push({newx,newy});
                    visb[newx][newy]=true;
                }
            }
        }
        q.push(mecho);
        vism[mecho.first][mecho.second]=true;
        if(distb[mecho.first][mecho.second]<=eating_time){q.pop();}
        while(!q.empty()){
            int x,y;
            tie(x,y)=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int newx=x+mx[i];
                int newy=y+my[i];
                if(valid_sit(newx,newy)&&!vism[newx][newy]&&(mecho_reached(distm[x][y]+1,distb[newx][newy]-eating_time))){
                    distm[newx][newy]=distm[x][y]+1;
                    q.push({newx,newy});
                    vism[newx][newy]=true;
                }
            }
        }
        bool reached=false;
        for(int i=0;i<4;i++){
            int newx=home.first+mx[i];
            int newy=home.second+my[i];
            if(valid_sit(newx,newy)&&(mecho_reached(distm[newx][newy],distb[newx][newy]-eating_time)&&vism[newx][newy])){
                reached=true;
            }
        }
        if(reached){
            l=eating_time+1;
        }
        else{
            r=eating_time-1;
        }
    }
    cout << l-1 << '\n';
}   