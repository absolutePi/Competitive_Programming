#include <bits/stdc++.h>

using namespace std;

const char TIPPED = '0';

bool flip(int r,int c, vector<vector<bool>> &v){
    if(v[r][c]){
        for(int i=0;i<=r;i++){
            for(int j=0;j<=c;j++){v[i][j]=!v[i][j];}
        }
        return true;
    }
    return false;
}

int main(){
    freopen("cowtip.in","r",stdin);
    freopen("cowtip.out","w",stdout);
    int n;
    cin >> n;
    vector<vector<bool>> v(n,vector<bool>(n));
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<n;j++){v[i][j] = str[j] != TIPPED;}
    }
    int x = n-1,y=n-1,cnt=0;
    while(x>=0&&y>=0){
        cnt+=flip(x,y,v);
        if(x!=y){
            cnt+=flip(y,x,v);
        }
        if(x>0)x--;
        else{
            y--;
            x=y;
        }
    }
    cout << cnt;
}