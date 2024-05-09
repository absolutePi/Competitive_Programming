#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    vector<int> wu(n);
    for(auto &i : wu){cin >> i;}
    multiset<int> bits;
    for(int i=0;i<m;i++){
        int t;
        cin >> t;
        bits.insert(t);
    } 
    for(int i=0;i<q;i++){
        int s,k;
        cin >> s >> k;
        auto it = bits.begin();
        while(it!=bits.end()){
            
        }
    }
}