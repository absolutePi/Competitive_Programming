#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n),v2(n);
    bool check = false;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=1;i<n;i++){
        if(v[i]<v[i-1]){
            check = true;
            break;
        }
    }
    if(!check){
        cout << "yes" << "\n" << "1 1";
        return 0;
    }
    int l=0,r=n-1;
    while(l<n-1 && v[l]<v[l+1])l++;
    while(r>0 && v[r]>v[r-1])r--;
    reverse(v.begin()+l,v.begin()+r+1);
    for(int i=0;i<n-1;i++){
        if(v[i]>v[i+1]){
            cout << "no";
            return 0;
        }
    }
    int mn = min(l,r),mx = max(l,r);
    cout << "yes" << "\n" << mn+1 << " " << mx+1;
}