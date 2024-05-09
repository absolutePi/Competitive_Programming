#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    int n;
    cin >> n;
    vector<vector<int>> v(n+1,vector<int>(3,0));
    for(int i=1;i<=n;i++){
        char c;
        cin >> c;
        if(c=='H'){
            v[i][0]++;
        }
        if(c=='P'){
            v[i][1]++;
        }
        if(c=='S'){
            v[i][2]++;
        }
        for(int j=0;j<3;j++){
            v[i][j]+=v[i-1][j];
        }
    }
    int ans=-1;
    for(int i=1;i<=n;i++){
        int mxtop=-1,mxbottom=-1;
        for(int j=0;j<3;j++){
            mxtop = max(mxtop,v[i][j]);
        }
        for(int j=0;j<3;j++){
            mxbottom = max(mxbottom,v[n][j]-v[i][j]);
        }
        ans = max(ans,mxtop+mxbottom);
    }
    cout << ans;
}