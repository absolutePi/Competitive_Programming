#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i : v){cin >> i;}
    int ans=INT_MIN,curr_sum=0,ansl,ansr;
    for(int l=0,r=0;r<n;r++){
        if(v[r]>curr_sum+v[r]){
            l=r;
            curr_sum=v[r];
        }
        else{
            curr_sum+=v[r];
        }
        if(curr_sum>ans){
            ans=curr_sum;
            ansl=l;
            ansr=r;
        }
    }
    if(ans<=0){
        cout << "Empty sequence" << '\n';
    }
    else{
        for(int i=ansl;i<=ansr;i++){
            cout << v[i] << ' ';
        }
        cout << '\n' << ans << '\n';
    }
}