#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<char>> grid(n+5,vector<char>(m+5));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    for(int j=0;j<m;j++){
        int a,i;
        cin >> a;
        while(a--){
            i=-1;
            while(grid[i+1][j]=='.'&&(i+1)<n){
                i++;
            }
            if(i==-1){break;}
            grid[i][j]='#';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << grid[i][j];
        }
        cout << '\n';
    }
}