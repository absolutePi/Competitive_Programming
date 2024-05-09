#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,q;
    cin >> n >> q;
    vector<vector<int>> v(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        string str;
        cin >> str;
        for(int j=1;j<=n;j++){
            v[i][j] = str[j-1]=='*' ? 1 : 0;
        }
    }
    //pushing row prefix
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            v[i][j] += v[i][j-1];
        }
    }
    //pushing column prefix
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            v[i][j]+=v[i-1][j];
        }
    }
    while(q--){
        int i1,j1,i2,j2;
        cin >> i1 >> j1 >> i2 >> j2;
        cout << v[i2][j2] - v[i2][j1-1] - v[i1-1][j2] + v[i1-1][j1-1] << endl;
    }
}   