#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> v1,v2;
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        if(a>b)swap(a,b);
        v1.push_back({a,b});
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        if(a>b)swap(a,b);
        v2.push_back({a,b});
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    if(v1==v2){
        cout << "Y";
    }
    else{
        cout << "N";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<5;i++){
        solve();
    }
}

