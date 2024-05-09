#include <bits/stdc++.h>

using namespace std;

const int N = 3000;
int grid[N][N];
int ans;

bool is_comfortable(int i,int j);
void adjust(int i,int j);
void make_uncomfortable(int i,int j);

bool is_comfortable(int i,int j){
    bool up = grid[i-1][j]!=0;
    bool right = grid[i][j+1]!=0;
    bool down = grid[i+1][j]!=0;
    bool left = grid[i][j-1]!=0;
    return (int)up+(int)right+(int)down+(int)left==3;
}

void adjust(int i,int j){
    if(grid[i][j]!=0&&is_comfortable(i,j)){
        make_uncomfortable(i,j);
    }
    if(grid[i+1][j]!=0&&is_comfortable(i+1,j)){
        make_uncomfortable(i+1,j);
    }
    if(grid[i-1][j]!=0&&is_comfortable(i-1,j)){
        make_uncomfortable(i-1,j);
    }
    if(grid[i][j+1]!=0&&is_comfortable(i,j+1)){
        make_uncomfortable(i,j+1);
    }
    if(grid[i][j-1]!=0&&is_comfortable(i,j-1)){
        make_uncomfortable(i,j-1);
    }
    return;
}

void make_uncomfortable(int i,int j){
    if(grid[i-1][j]==0){
        grid[i-1][j]=2;
        ans++;
        adjust(i-1,j);
    }
    else if(grid[i+1][j]==0){
        grid[i+1][j]=2;
        ans++;
        adjust(i+1,j);
    }
    else if(grid[i][j-1]==0){
        grid[i][j-1]=2;
        ans++;
        adjust(i,j-1);
    }
    else if(grid[i][j+1]==0){
        grid[i][j+1]=2;
        ans++;
        adjust(i,j+1);
    }
    return;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        a+=1500;
        b+=1500;
        if(grid[a][b]==0){
            grid[a][b]=1;
        }
        else if(grid[a][b]==2){
            grid[a][b]=1;
            ans--;
        }
        adjust(a,b);
        cout << ans << endl;
    }
}