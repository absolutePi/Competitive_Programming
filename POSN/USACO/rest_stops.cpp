#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

int main(){
    freopen("reststops.in","r",stdin);
    freopen("reststops.out","w",stdout);
    //ios::sync_with_stdio(false);
    //in.tie(NULL);
    int l,stop_num,fj,b;
    cin >> l >> stop_num >> fj >> b;
    vector<int> x(stop_num);
    vector<int> c(stop_num);
    for(int i=0;i<stop_num;i++){cin >> x[i] >> c[i];}

    vector<bool> good(stop_num);
    int mx_tastiness = 0;
    for(int i=stop_num-1;i>=0;i--){
        if(c[i]>mx_tastiness){
            mx_tastiness=c[i];
            good[i]=true;
        }
    }

    ll last_stop = 0;
    ll ans = 0;
    for(int i=0;i<stop_num;i++){
        if(good[i]){
            ll gap = x[i]-last_stop;
            ans+= (fj-b)*gap*c[i];
            last_stop=x[i];
        }
    }
    cout << ans;
}