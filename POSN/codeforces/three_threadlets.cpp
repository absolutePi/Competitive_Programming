#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

void solve(){
    vector<int> v(3);
    for(int i=0;i<3;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int cnt=0;
    while(v[1]!=v[0] && v[1]>v[0]){
        cnt++;
        v[1]-=v[0];
    }
    while(v[2]!=v[0] && v[2]>v[0]){
        cnt++;
        v[2]-=v[0];
    }
    if(cnt>3){
        cout << "NO" << endl;
        return;
    }
    if(v[0]==v[1] && v[1]==v[2]){
        cout << "YES" << endl;
        return;
    }
    else{
        cout << "NO" << endl;
        return;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}