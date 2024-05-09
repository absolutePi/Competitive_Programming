#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

int main(){
    freopen("cardgame.in","r",stdin);
    freopen("cardgame.out","w",stdout);
    //ios::sync_with_stdio(false);
    //in.tie(NULL);
    int n;
    cin >> n;
    //temp set
    set<int> s;
    for(int i=1;i<=n*2;i++){
        s.insert(i);
    }
    //getting elsie's cards
    vector<int> e(n);
    for(int i=0;i<n;i++){
        cin >> e[i];
        s.erase(e[i]);
    }
    //getting bessie's cards
    set<int> bf,bs;
    int i=0;
    for(auto cards : s){
        if(i<n/2){
            bs.insert(cards);
        }
        else if(i<n){
            bf.insert(cards);
        }
        else{break;}
        i++;
    }
    //getting ans
    int ans=0;
    //first half
    for(int i=0;i<n/2;i++){
        auto it = bf.upper_bound(e[i]);
        if(it!=bf.end()){
            ans++;
            bf.erase(it);
        }
        else{
            bf.erase(bf.begin());
        }
    }
    //second half
    for(int i=n/2;i<n;i++){
        auto it = bs.upper_bound(e[i]);
        if(it!=bs.begin()){
            it--;
            ans++;
            bs.erase(it);
        }
        else{
            it = bs.end();
            it--;
            bs.erase(it);
        }
    }
    cout << ans;
}