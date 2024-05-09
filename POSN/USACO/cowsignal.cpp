#include <bits/stdc++.h>

using namespace std;

char arr[11][11];

int main(){
    freopen("cowsignal.in","r",stdin);
    int m,n,k;
    cin >> m >> n >> k;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    freopen("cowsignal.out","w",stdout);
    for(int i=0;i<m;i++){
        for(int x=0;x<k;x++){
            for(int j=0;j<n;j++){
                for(int y=0;y<k;y++){
                    cout << arr[i][j];
                }
            }
            cout << "\n";
        }
    }
}