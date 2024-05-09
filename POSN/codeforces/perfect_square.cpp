#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

void solve(){
    int n,cnt=0;
    cin >> n;
    vector<vector<char>> matrix(n,vector<char>(n)),rotated(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> matrix[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            rotated[i][j]=matrix[n-1-j][i];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(rotated[i][j]!=matrix[i][j])cnt+=abs(rotated[i][j]-matrix[i][j]);
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout << matrix[i][j];
    //     }
    //     cout << endl;
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout << rotated[i][j];
    //     }
    //     cout << endl;
    // }
    cout << cnt/2 << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}