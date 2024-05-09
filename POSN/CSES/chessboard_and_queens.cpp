#include <bits/stdc++.h>

using namespace std;

int board[8][8],rcnt;

void func(int board[8][8],int cnt){
    if(cnt==8){
        rcnt++;
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]==0){
                // for(int k=i-1;k>=0;k--){
                //     for(int l=j)
                // }
                board[i][j]=2;
                cnt++;
                func(board,cnt);
            }
        }
    }
}

int main(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            char a;
            cin >> a;
            if(a=='*')board[i][j]=1;
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout << board[i][j];
        }
        cout << "\n";
    }
}