#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<int> v;

bool good(int r){
    int first_cow = v[0],cows_amt=1;
    for(auto i : v){
        if(i-first_cow>r*2){
            cows_amt++;first_cow=i;
            if(cows_amt>k){return false;}
        }
    }
    return true;
}

int main(){
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    cin >> n >> k;
    v.resize(n);
    for(auto &i : v){cin >> i;}
    sort(v.begin(),v.end());
    int l=0,r=v[n-1]-v[0];
    while(l<r){
        int mid = l+(r-l)/2;
        if(good(mid))r=mid;
        else l=mid+1;
    }
    cout << l;
}   
