#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
vector<ll> arr;
ll n,x,a,y,b,k;
 
bool works(ll tickets_selling){
    vector<ll> percentages(tickets_selling,0);
    for(ll i=a-1;i<tickets_selling;i+=a){
        percentages[i]+=x;
    }
    for(ll i=b-1;i<tickets_selling;i+=b){
        percentages[i]+=y;
    }
    sort(percentages.begin(),percentages.end(),greater<ll>());
    ll res=0;
    for(ll i=0;i<tickets_selling;i++){
        res+=arr[i]*percentages[i]/100;
    }
    return res>=k;
}
 
void solve(){
    cin >> n;
    arr.resize(n);
    for(auto &i : arr){cin >> i;}
    sort(arr.begin(),arr.end(),greater<ll>());
    cin >> x >> a >> y >> b >> k;
    ll l=1,r=n,mid,ans=-1;
    while(l<=r){
        mid=l+(r-l)/2;
        if(works(mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout << ans << endl;
}
 
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll q;
    cin >> q;
    for(ll i=0;i<q;i++){
        solve();
    }
}