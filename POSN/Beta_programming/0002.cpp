#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,mn=INT_MAX,mx=INT_MIN;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        mn = min(mn,x);
        mx = max(mx,x);
    }
    cout << mn << "\n" << mx;
}