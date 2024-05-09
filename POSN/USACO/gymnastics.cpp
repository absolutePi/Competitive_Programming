#include <bits/stdc++.h>

using namespace std;


int main(){
    freopen("gymnastics.in","r",stdin);
    freopen("gymnastics.out","w",stdout);
    int k,n;    cin >> k >> n;
    vector<vector<int>> v(n+1,vector<int>(n+1,0));
    vector<int> ranks(n+1);
    for(int t=0;t<k;t++){
        ranks.clear();
        for(int i=0;i<n;i++){
            cin >> ranks[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                v[ranks[i]][ranks[j]]++;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(v[i][j]==k)ans++;
        }
    }
    cout << ans;
}