#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define f first
#define s second

int N;
ll M;

bool check(vector<pair<ll,ll>> v,ll target){
    ll pos=v[0].f;
    ll i=0;
    ll amt=0;
    while(amt<N){
        if(v[i].f>=pos){
            pos=v[i].f;
        }
        if(v[i].f<=pos&&v[i].s>=pos){
            pos+=target;
            amt++;
        }
        else{i++;}
        if(i>=v.size()){return false;}
    }
    return true;
}

int main(){
    freopen("socdist.in","r",stdin);
    freopen("socdist.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> N >> M;
    vector<pair<ll,ll>> nums(M);
    for(int i=0;i<M;i++){
        cin >> nums[i].f >> nums[i].s;
    }
    sort(nums.begin(),nums.end());
    ll l=1,r=nums[nums.size()-1].s-nums[0].f;
    while(l<r){
        ll mid = l+(r-l+1)/2;
        if(check(nums,mid)){
            l=mid;
        }
        else{
            r=mid-1;
        }
    }
    cout << l;
}