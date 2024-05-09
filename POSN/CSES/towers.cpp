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
    multiset<int> s;
    int ans=0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        auto it = s.upper_bound(x);
        if(it==s.end()){
            s.insert(x);
            ans++;
        }
        else{
            s.erase(it);
            s.insert(x);
        }
    }
    cout << s.size();
}  