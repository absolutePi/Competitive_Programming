#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

int main(){
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);
    int n,k;
    cin >> n >> k;
    vector<int> d(n);
    for(auto &i : d){cin >> i;}
    sort(all(d));
    
    vector<int> can_take(n);
    int r=0;
    for(int l=0;l<n;l++){
        while(d[r]-d[l]<=k && r<n){
            r++;
        }
        can_take[l]=r-l;
    }

    vector<int> suffix_mx(n+1);
    suffix_mx[n]=0;
    for(int i=n-1;i>=0;i--){
        suffix_mx[i] = max(suffix_mx[i+1],can_take[i]);
    }

    int ans=0;
    for(int i=0;i<n;i++){
        ans = max(ans,can_take[i]+suffix_mx[i+can_take[i]]);
    }
    cout << ans;
}