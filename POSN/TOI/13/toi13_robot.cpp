#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const int INF = 1e9+7;
int dist[N][N],n,m;
int mx[]={1,-1,0,0},my[]={0,0,1,-1};

bool within(int x,int y){
    return (x>=0&&y>=0&&x<n&&y<m);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<pair<int,int>> targets;
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin >> c;
            dist[i][j]=INF;
            if(c=='X'){
                q.push({i,j});
                dist[i][j]=0;
            }
            if(c=='W'){
                dist[i][j]=0;
            }
            if(c=='A'){
                targets.push_back({i,j});
            }
        }
    }
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newx=x+mx[i];
            int newy=y+my[i];
            if(within(newx,newy)&&(dist[x][y]+1<dist[newx][newy])){
                dist[newx][newy]=dist[x][y]+1;
                q.push({newx,newy});
            }
        }
    }
    int sum=0,num=0;
    for(auto i: targets){
        if(dist[i.first][i.second]!=INF){
            num++;
            sum+=(dist[i.first][i.second]*2);
        }
    }
    cout << num << ' ' << sum << "\n";
}   