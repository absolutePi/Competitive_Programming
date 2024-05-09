#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,mn = INT_MAX,mx = INT_MIN;
    int long long mncnt=0,mxcnt=0;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        mx = max(mx,v[i]);
        mn = min(mn,v[i]);
    }
    for(int i=0;i<n;i++){
        if(v[i]==mx)mxcnt++;
        else if(v[i]==mn)mncnt++;
    }
    cout << mx-mn << " ";
    if(mn==mx)cout << "1";
    else cout << mxcnt*mncnt;
}