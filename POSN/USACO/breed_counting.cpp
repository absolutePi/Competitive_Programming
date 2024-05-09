#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("bcount.in","r",stdin);
    freopen("bcount.out","w",stdout);
    int n,q;
    cin >> n >> q;
    vector<vector<int>> v(n+1,vector<int>(3,0));
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        v[i][x-1]++;
        for(int j=0;j<3;j++){
            v[i][j]+=v[i-1][j];
        }
    }
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        for(int i=0;i<3;i++){
            int x = v[r][i]-v[l-1][i];
            cout << x;
            if(i!=2)cout << " ";
        }
        cout << endl;
    }
}