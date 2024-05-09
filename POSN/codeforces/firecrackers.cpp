#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll time_bef_caught;

bool works(ll dropping,vector<ll> &fcs){
    ll curr_time=1;
    for(ll i=dropping-1;i>=0;i--){
        if(curr_time+fcs[i]>time_bef_caught){
            return false;
        }
        else{
            curr_time++;
        }
    }
    return true;
}

void solve(){
    ll n,fc_num,hooligan_pos,guard_pos;
    cin >> n >> fc_num >> hooligan_pos >> guard_pos;
    vector<ll> fcs(fc_num);
    for(auto &i : fcs){cin >> i;}
    sort(fcs.begin(),fcs.end());
    ll max_fc = min(abs(hooligan_pos-guard_pos)-1,fc_num);
    if(hooligan_pos<guard_pos){
        time_bef_caught=guard_pos-1;
    }
    else if(hooligan_pos>guard_pos){
        time_bef_caught=n-guard_pos;
    }
    else{
        return;
    }
    ll l=0,r=max_fc,mid,ans;
    while(l<=r){
        mid=l+(r-l)/2;
        if(works(mid,fcs)){
            ans=mid;
            l=mid+1;
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
    ll t;
    cin >> t;
    for(ll i=0;i<t;i++){
        solve();
    }
}