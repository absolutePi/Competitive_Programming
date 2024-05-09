#include <bits/stdc++.h>

using namespace std;

const int N = 4000;
string snow[N];
int dept[N][N];
int h,w;

int mx[]={1,-1,0,0},my[]={0,0,1,-1};

bool inside(int x,int y){
    return (x>=0&&y>=0&&x<h&&y<w&&snow[x][y]!='.');
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> h >> w;
    for(int i=0;i<h;i++){
        cin >> snow[i];
    }
    deque<pair<int,int>> q;
    dept[0][0]=1;
    q.push_back({0,0});
    int ans=1;
    while(!q.empty()){
        auto curr = q.front();
        q.pop_front();
        ans=max(ans,dept[curr.first][curr.second]);
        for(int i=0;i<4;i++){
            int x=curr.first+mx[i];
            int y=curr.second+my[i];
            if(inside(x,y)&&dept[x][y]==0){
                if(snow[x][y]==snow[curr.first][curr.second]){
                    dept[x][y]=dept[curr.first][curr.second];
                    q.push_front({x,y});
                }
                else{
                    dept[x][y]=dept[curr.first][curr.second]+1;
                    q.push_back({x,y});
                }
            }
        }
    }
    cout << ans << '\n';
}   