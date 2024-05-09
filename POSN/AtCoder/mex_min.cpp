#include <bits/stdc++.h>

using namespace std;

const int N = 15e5+5;
int cnt[N];

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for(auto &i : v){cin >> i;}
    set<int> s;
    for(int i=0;i<=N;i++){
        s.insert(i);
    }
    for(int i=0;i<m;i++){
        cnt[v[i]]++;
        if(s.count(v[i])){
            s.erase(v[i]);
        }
    }
    int ans=*s.begin();
    for(int i=m;i<n;i++){
        cnt[v[i-m]]--;
        if(cnt[v[i-m]]==0){
            s.insert(v[i-m]);
        }
        cnt[v[i]]++;
        if(s.count(v[i])){
            s.erase(v[i]);
        }
        ans=min(ans,*s.begin());
    }
    cout << ans << '\n';
}       