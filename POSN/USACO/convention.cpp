#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

int n,m,c;
vector<int> v;

bool good(int k){   
    int first_cow = v[0];
    int bus_amt=1;
    int cows_amt = 0;
    for(auto i : v){
        cows_amt++;
        if(cows_amt>c||i-first_cow>k){
            bus_amt++;
            first_cow=i;
            cows_amt=1;
            if(bus_amt>m){return false;}
        }
    }
    return true;
}

int main(){
    freopen("convention.in","r",stdin);
    freopen("convention.out","w",stdout);
    //ios::sync_with_stdio(false);
    //in.tie(NULL);
    cin >> n >> m >> c;
    v.resize(n);
    for(auto &i : v){cin >> i;}
    sort(all(v));
    int l=0,r=v[n-1]-v[0];
    while(l<r){
        int mid = l+(r-l)/2;
        if(good(mid)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout << l;
}