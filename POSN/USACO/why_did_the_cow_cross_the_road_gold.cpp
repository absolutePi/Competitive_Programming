#include <bits/stdc++.h>

using namespace std;

int n,t;
int mx[]={1, 0, -1, 0, 3, 0, -3, 0, 2, 2, 1, 1, -1, -1, -2, -2};
int my[]={0, 1, 0, -1, 0, 3, 0, -3, 1, -1, 2, -2, 2, -2, 1, -1};


bool within(int x,int y){
    return (x>=0&&y>=0&&x<n&&y<n);
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("visitfj.in","r",stdin);
    freopen("visitfj.out","w",stdout);
    cin >> n >> t;
    vector<vector<int>> cost(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> cost[i][j];
        }
    }
    vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
    vector<vector<bool>> vis(n,vector<bool>(n));
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> q;
    q.push({0,0,0});//cost row column
    dist[0][0]=0;
    while(!q.empty()){
        tuple<int,int,int> curr=q.top();
        q.pop();
        int row=get<1>(curr);
        int col=get<2>(curr);
        if(vis[row][col]){continue;}
        vis[row][col]=true;
        for(int i=0;i<16;i++){
            int r=row+mx[i];
            int c=col+my[i];
            if(!within(r,c)){continue;}
            if(dist[r][c]>dist[row][col]+3*t+cost[r][c]){
                dist[r][c]=dist[row][col]+3*t+cost[r][c];
                q.push({dist[r][c],r,c});
            }
        }
        int temp=n-1-row+n-1-col;
        if(temp<3){
            dist[n-1][n-1]=min(dist[n-1][n-1],dist[row][col]+temp*t);
        }
    }
    cout << dist[n-1][n-1] << '\n';
}