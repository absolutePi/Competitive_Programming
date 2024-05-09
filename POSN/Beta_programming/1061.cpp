#include <bits/stdc++.h>

using namespace std;

#define T tuple<int,int,int>
const int N = 25;
int a[N][N];
bool vis[N][N];
int mx[]={1,-1,0,0},my[]={0,0,1,-1};
int s,n,m;

bool within(int x,int y){
    return (x>=1&&y>=1&&x<=s&&y<=s);
}

int main(){
    cin >> s >> m >> n;
    for(int i=1;i<=s;i++){
        for(int j=1;j<=s;j++){
            cin >> a[i][j];
        }
    }
    int ans=INT_MIN;
    priority_queue<T> q;//temp x y
    q.push({a[n][m],n,m});
    while(!q.empty()){
        int temp,x,y;
        tie(temp,x,y)=q.top();q.pop();
        if(vis[x][y])continue;
        vis[x][y]=true;
        ans=max(ans,temp);
        for(int i=0;i<4;i++){
            int newx=x+mx[i];
            int newy=y+my[i];
            if(within(newx,newy)&&(a[newx][newy]>temp)&&(a[newx][newy]!=100)){
                q.push({a[newx][newy],newx,newy});
            }
        }
    }
    cout << ans << '\n';
}