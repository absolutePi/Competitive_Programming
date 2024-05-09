#include <bits/stdc++.h>

using namespace std;

bool arr[20000][1000];

int main(){
    int t;
    cin >> t;
    for(int r=0;r<t;r++){
        int m,n=0;
        cin >> m;
        int ar[m],clone[m];
        for(int i=0;i<m;i++){
            cin >> ar[i];
            clone[i] = ar[i];
            n = max(n,ar[i]);
        }
        for(int j=0;j<m;j++){
            int x=n-1;
            while(clone[j]--){
                arr[x][j]=1;
                x--;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j])cout << "1";
                else cout << "0";
            }
            cout << "\n";
        }
    }
}