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
    ll a,b,c;
    cin >> a >> b >> c;
    ll m;
    cin >> m;
    vector<pair<ll,ll>> v;
    for(ll i=0;i<m;i++){
        ll price;
        string type;
        cin >> price >> type;
        ll t_num = type=="PS/2";
        v.pb({price,t_num});
    }
    sort(all(v));

    ll total=0,com=0;
    for(auto i : v){
        if(i.s==0){
            if(a){
                a--;
                total+=i.f;
                com++;
            }
            else if(c){
                c--;
                total+=i.f;
                com++;
            }
        }
        else{
            if(b){
                b--;
                total+=i.f;
                com++;
            }
            else if(c){
                c--;
                total+=i.f;
                com++;
            }
        }
    }
    cout << com << " " << total;
}