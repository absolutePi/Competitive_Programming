#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

int main(){
    //ios::sync_with_stdio(false);
    //in.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> b(n),g(m);
    ll ans=0;
    for(auto &i : b){
        cin >> i;
        ans+=i;
    }
    for(auto &i : g){cin >> i;}

    ans*=m;
    sort(all(b));
    sort(all(g));

    if(b[n-1]>g[0]){cout << "-1";return 0;}

    for(int i=1;i<m;i++){ans+=g[i]-b[n-1];}
    if(g[0]!=b[n-1]){ans+=g[0]-b[n-2];}
    cout << ans;
}