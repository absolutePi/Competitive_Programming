#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
int n;
bool visited[N][N];
char grid[N][N];
int currA,currP;
int ansA=INT_MIN,ansP=INT_MAX;

void floodfill(int r,int c){
    if(r<0||r>=n||c<0||c>=n||grid[r][c]=='.'){
        currP++;
        return;
    }
    if(visited[r][c]){
        return;
    }
    visited[r][c]=true;
    currA++;
    floodfill(r+1,c);
    floodfill(r-1,c);
    floodfill(r,c+1);
    floodfill(r,c-1);
    return;
}

int main(){
    freopen("perimeter.in","r",stdin);
    freopen("perimeter.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]&&grid[i][j]=='#'){
                floodfill(i,j);
                if(currA==ansA){
                    ansP=min(currP,ansP);
                }
                else if(currA>ansA){
                    ansA=currA;
                    ansP=currP;
                }
                currA = currP = 0;
            }
        }
    }
    cout << ansA << ' ' << ansP << endl;
}