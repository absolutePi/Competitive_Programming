#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int grid[N][N];
bool vis[N][N][1005];
vector<pair<int,int>> dir[2] = {{{-1,0},{-1,1},{0,-1},{0,1},{1,0},{1,1}},{{-1,-1},{-1,0},{0,-1},{0,1},{1,-1},{1,0}}};
int m,n;

bool within(int x,int y){
    return (x>=0&&y>=0&&x<m&&y<n);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }
    queue<tuple<int,int,int>> q;
    for(int i=-1;i<=1;i++){
        int start=(m-1)/2;
        if(grid[start+i][0]!=0){
            vis[start+i][0][1]=true;
            q.push({start+i,0,1});
        }
    }
    while(!q.empty()){
        int x,y,steps;
        tie(x,y,steps)=q.front();
        q.pop();
        if((x==(m-1)/2)&&(y==n-1)){
            cout << steps << '\n';
            return 0;
        }
        steps++;
        for(auto i : dir[x%2]){
            int newx=x+i.first;
            int newy=y+i.second;
            if(!within(newx,newy)||grid[newx][newy]==0||vis[newx][newy][steps])continue;
            if(steps%grid[newx][newy])continue;
            vis[newx][newy][steps]=true;
            q.push({newx,newy,steps});
        }
    }
}