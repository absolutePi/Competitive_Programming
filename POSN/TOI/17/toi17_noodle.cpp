#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int N = 1e5+5;
ll a[N],n,m,k;
ll l,r,mid,ans;

bool works(){
    ll curr_sum=0,components=0;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for(ll i=0;i<n;i++){
        if(pq.size()<k){
            curr_sum+=a[i];
            pq.push(a[i]);
        }
        else if(pq.top()<a[i]){
            curr_sum-=pq.top();
            pq.pop();
            curr_sum+=a[i];
            pq.push(a[i]);
        }
        if(pq.size()>=k){
            if(curr_sum>=mid){
                curr_sum=0;
                components++;
                while(!pq.empty())pq.pop();
            }
            if(components>=m)return true;
        }
        
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    l=0,r=LLONG_MAX,ans=0;
    while(l<=r){
        mid=l+(r-l)/2;
        if(works()){
            l=mid+1;
            ans=mid;
        }
        else{
            r=mid-1;
        }
    }
    cout << ans << '\n';
}