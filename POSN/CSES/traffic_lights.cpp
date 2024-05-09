#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x,n;
    cin >> x >> n;
    set<int> lights{0,x};
    multiset<int> gap{x};
    for(int i=0;i<n;i++){
        int pos;
        cin >> pos;

        auto it1 = lights.upper_bound(pos);
        auto it2 = it1;
        it2--;

        gap.erase(gap.find(*it1 - *it2));
        gap.insert(*it1-pos);
        gap.insert(pos-*it2);
        lights.insert(pos);

        auto ans = gap.end();
        ans--;
        cout << *ans << " ";
    }
}