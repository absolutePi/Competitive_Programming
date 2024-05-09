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
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(auto &i : v){cin >> i.s >> i.f;}
    sort(all(v));
    int last_end=0,ans=0;
    for(int i=0;i<n;i++){
        if(v[i].s>=last_end){
            last_end=v[i].f;
            ans++;
        }
    }
    cout << ans;
}