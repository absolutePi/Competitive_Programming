#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define aint(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

int main(){
    //ios::sync_with_stdio(false);
    //in.tie(NUint);
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> movies(n);//end and start;
    for(auto &i : movies){cin >> i.s >> i.f;}
    sort(aint(movies));

    multiset<int> ends;
    for(int i=0;i<m;i++){ends.insert(0);}
    int ans=0;
    for(int i=0;i<n;i++){
        auto it = ends.upper_bound(movies[i].s);
        if(it==ends.begin()){continue;}
        it--;
        ends.erase(it);
        ends.insert(movies[i].f);
        ans++;
    }
    cout << ans;
}