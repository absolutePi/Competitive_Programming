#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

int main(){
    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);
    //ios::sync_with_stdio(false);
    //in.tie(NULL);
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    for(auto &i : v){cin >> i;}
    sort(all(v));

    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        cout << upper_bound(all(v),r)-lower_bound(all(v),l) << endl;
    }
}