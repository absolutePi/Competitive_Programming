#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
char grid[N+1][N+1];
vector<vector<int>> dist(N+1,vector<int>(N+1,INT_MAX));
int n,m;
// char to[N+1][N+1];
vector<vector<char>> to(N+1,vector<char>(N+1,'.'));

int mx[]={1,-1,0,0},my[]={0,0,1,-1};

bool inside(int x,int y){
    return (x>=0&&y>=0&&x<n&&y<m&&grid[x][y]!='#');
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> m;
    pair<int,int> start,end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];  
            if(grid[i][j]=='A'){
                start={i,j};
            }
            if(grid[i][j]=='B'){
                end={i,j};
            }
        }
    }
    queue<pair<int,int>> q;
    q.push(start);
    dist[start.first][start.second]=0;
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=curr.first+mx[i];
            int y=curr.second+my[i];
            if(inside(x,y)&&dist[x][y]==INT_MAX){
                dist[x][y]=dist[curr.first][curr.second]+1;
                q.push({x,y});
                if(i==0){
                    to[x][y]='D';
                }
                else if(i==1){
                    to[x][y]='U';
                }
                else if(i==2){
                    to[x][y]='R';
                }
                else{
                    to[x][y]='L';
                }
            }
        }
    }
    if(dist[end.first][end.second]==INT_MAX){
        cout << "NO";
    }
    else{
        cout << "YES" << '\n' << dist[end.first][end.second] << '\n';
        vector<char> ans;
        int i=end.first,j=end.second;
        while(i!=start.first||j!=start.second){
            ans.push_back(to[i][j]);
            if(to[i][j]=='L'){
                j++;
            }
            else if(to[i][j]=='R'){
                j--;
            }
            else if(to[i][j]=='U'){
                i++;
            }
            else{
                i--;
            }
        }
        reverse(ans.begin(),ans.end());
        for(auto i : ans){
            cout << i;
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << to[i][j];
    //     }
    //     cout << '\n';
    // }
}   