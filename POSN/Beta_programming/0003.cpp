#include <bits/stdc++.h>

using namespace std;

int arr[101][101];

int main(){
    int n,m;
    cin >> n >> m;
    for(int k=0;k<2;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x;
                cin >> x;
                arr[i][j]+=x;
                if(k==1)cout << arr[i][j] << " ";
            }
            if(k==1)cout << "\n";
        }
    }
}