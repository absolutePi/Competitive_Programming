#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

int last_true(int lo,int hi,function<bool(int)> f){
    lo--;
    while(lo<hi){
        int mid = lo+(hi-lo+1)/2;
        if(f(mid)){
            lo = mid;
        }
        else{
            hi = mid-1;
        }
    }
    return lo;
}

int main(){
    //ios::sync_with_stdio(false);
    //in.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &i : v){cin >> i;}
    sort(all(v));
    cout << last_true(1,2e9,[&](int x){
        ll ops_needed=0;
        for(int i=n/2;i<n;i++){
            ops_needed+=max(0,x-v[i]);
        }
        return ops_needed<=k;
    });
}