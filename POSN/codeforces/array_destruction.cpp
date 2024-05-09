#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

vector<int> check(int n,vector<int> a,int x){
    multiset<int> s;
    for(auto i : a){
        s.insert(i);
    }
    vector<int> res;
    for(int i=0;i<n;i++){
        auto it1 = s.end();
        it1--;
        s.erase(it1);
        int y = x-*it1;
        auto it2 = s.find(y);
        if(it2==s.end()){
            return {};
        }
        res.pb(y);
        res.pb(x-y);
        s.erase(it2);
        x = max(y,x-y);
    }
    return res;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(2*n);
    for(auto &i : a){cin >> i;}
    sort(all(a));
    for(int i=0;i<2*n-1;i++){
        int x = a[i]+a[2*n-1];
        vector<int> res = check(n,a,x);
        if(res.size()){
            cout << "YES" << endl;
            cout << x << endl;
            for(int j=0;j<n*2;j+=2){
                cout << res[j] << " " << res[j+1] << endl;
            }
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    //ios::sync_with_stdio(false);
    //in.tie(NULL);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
}