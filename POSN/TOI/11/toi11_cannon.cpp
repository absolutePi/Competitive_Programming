#include <bits/stdc++.h>

using namespace std;

bool within(int start,int end,int pos){
    return (pos>=start&&pos<=end);
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,m,k,l;
    cin >> n >> m >> k >> l;
    vector<int> cannons(n);
    for(auto &i : cannons){cin >> i;}
    for(int t=0;t<k;t++){
        int ans=0;
        auto it=cannons.begin();
        for(int i=0;i<m;i++){
            int point;
            cin >> point;
            auto start=lower_bound(it,cannons.end(),point-l);
            it=upper_bound(it,cannons.end(),point+l);
            ans+=it-start;
        }
        cout << ans << '\n';
    }
}