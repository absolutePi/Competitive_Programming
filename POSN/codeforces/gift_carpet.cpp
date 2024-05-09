#include <bits/stdc++.h>

using namespace std;

int main(){
    string str = "vika";
    int t;
    cin >> t;
    for(int v=0;v<t;v++){
        int n,m,cnt=0;
        cin >> n >> m;
        char arr[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> arr[i][j];
            }
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(arr[i][j]==str[cnt]){
                    cnt++;
                    break;
                }
            }
        }
        if(cnt==4)cout << "YES";
        else cout << "NO";
        puts("");
    }
}