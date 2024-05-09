#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;
int a[N],prf[N],suf[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<int> v;
    for(int i=0;i<n;i++){
        auto it=lower_bound(v.begin(),v.end(),(a[i]));
        if(it==v.end()){
            prf[i]=v.size();
            v.push_back(a[i]);
        }
        else{
            *it=a[i];
            prf[i]=it-v.begin();
        }
    }
    v.clear();
    for(int i=n-1;i>=0;i--){
        auto it=lower_bound(v.begin(),v.end(),(a[i]));
        if(it==v.end()){
            suf[i]=v.size();
            v.push_back(a[i]);
        }
        else{
            *it=a[i];
            suf[i]=it-v.begin();
    }
    }
    // for(int i=0;i<n;i++){
    //     cout << prf[i] << ' ';
    // }
    // cout << '\n';
    // for(int i=0;i<n;i++){
    //     cout << suf[i] << ' ';
    // }
    for(int i=0;i<q;i++){
        int index;
        cin >> index;
        cout << min(suf[index],prf[index]) << '\n';
    }
}