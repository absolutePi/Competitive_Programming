#include <bits/stdc++.h>

using namespace std;

const int N=20005;
bool grid[N][N];

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    int wtf=INT_MIN;
    for(int i=0;i<n;i++){
        int row,start,amnt;
        cin >> row >> start >> amnt;
        wtf=max(row,wtf);
        for(int j=start;j<start+amnt;j++){
            grid[row][j]=1;
        }
    }
    for(int i=1;i<=wtf;i++){
        for(int j=1;j<=70;j++){
            cout << (grid[i][j] ? 'x' : 'o');
        }
        cout << '\n';
    }
}