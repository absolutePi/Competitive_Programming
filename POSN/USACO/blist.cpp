#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+1;
int buckets[N],mx;

int main(){
    freopen("blist.in","r",stdin);
    freopen("blist.out","w",stdout);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int st,nd,b;
        cin >> st >> nd >> b;
        for(int j=st;j<=nd;j++){
            buckets[j]+=b;
        }
    }
    for(int i=0;i<=N;i++){
        mx = max(mx,buckets[i]);
    }
    cout << mx;
}