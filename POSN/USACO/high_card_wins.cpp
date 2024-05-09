#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

int main(){
    freopen("highcard.in","r",stdin);
    freopen("highcard.out","w",stdout);
    //ios::sync_with_stdio(false);
    //in.tie(NULL);
    int n;
    cin >> n;
    set<int> s;
    for(int i=1;i<=n*2;i++){
        s.insert(i);
    }
    vector<int> elsies(n);
    for(auto &i : elsies){
        cin >> i;
        s.erase(i);
    }

    int ans=0;
    for(int i=0;i<n;i++){
        auto it = s.upper_bound(elsies[i]);
        if(it==s.end()){continue;}
        else{
            ans++;
            s.erase(it);
        }
    }
    cout << ans;
}