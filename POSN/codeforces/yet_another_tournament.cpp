#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int &i : a){cin >> i;}
    auto b = a;
    sort(all(b));
    int ans=0;
    for(int i=0;i<n && b[i]<=m;i++){
        m-=b[i];
        ans++;
    }
    if(ans!=0 && ans!=n && a[ans]-b[ans-1]<=m)ans++;
    cout << n+1-ans << endl;
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