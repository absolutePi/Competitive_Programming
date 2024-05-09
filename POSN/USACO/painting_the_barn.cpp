#include <bits/stdc++.h>

using namespace std;

const int N = 1001;

int main(){
    freopen("paintbarn.in","r",stdin);
    freopen("paintbarn.out","w",stdout);
    int n,k;
    cin >> n >> k;
    vector<vector<int>> v(N+1,vector<int>(N+1));
    while(n--){
        int j1,i1,j2,i2;
        cin >> j1 >> i1 >> j2 >> i2;
        j1++;i1++;j2++;i2++;
        v[i1][j1]++;
        v[i2][j2]++;
        v[i1][j2]--;
        v[i2][j1]--;
    }
    int ans=0;
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            v[i][j] += v[i-1][j]+v[i][j-1]-v[i-1][j-1];
            if(v[i][j]==k){
                ans++;
            }
        }
    }
    cout << ans;
}