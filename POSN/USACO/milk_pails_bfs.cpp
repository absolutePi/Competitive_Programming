#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int dist[N][N];

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("pails.in","r",stdin);
    freopen("pails.out","w",stdout);
    int x,y,k,m;
    cin >> x >> y >> k >> m;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dist[i][j]=INT_MAX;
        }
    }
    queue<pair<int,int>> q;
    q.push({0,0});
    dist[0][0]=0;
    while(!q.empty()){
        auto curr=q.front();
        q.pop();

        int pourX = min(curr.first,y-curr.second);
        int pourY = min(curr.second,x-curr.first);
        int posx[]={x,0,curr.first-pourX,curr.first,curr.first,curr.first+pourY};
        int posy[]={curr.second,curr.second,curr.second+pourX,y,0,curr.second-pourY};
        for(int i=0;i<6;i++){
            if(dist[curr.first][curr.second]+1<=k&&dist[posx[i]][posy[i]]==INT_MAX){
                dist[posx[i]][posy[i]]=dist[curr.first][curr.second]+1;
                q.push({posx[i],posy[i]});
            }
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(dist[i][j]<=k){
                ans=min(ans,abs(i+j-m));
            }
        }
    }
    cout << ans << '\n';
}   