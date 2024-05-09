#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int> v;

bool works(int curr_max){
    for(int i=0;i<n;i++){
        int move_left=k;
        int need = curr_max;
        for(int j=i;j<n;j++){
            if(v[j]>=need){return true;}
            move_left-=need-v[j];
            need--;
            if(move_left<0){break;}
        }
    }
    return false;
}

void solve(){
    cin >> n >> k;
    v = vector<int>(n);
    for(auto &i : v){cin >> i;}
    int l=0,r=1e9,mid,ans;
    while(l<=r){
        mid=l+(r-l)/2;
        if(works(mid)){
            l=mid+1;
            ans=mid;
        }
        else{
            r=mid-1;
        }
    }
    cout << ans << '\n';
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
}