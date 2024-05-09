#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> bf(n+1,false);
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        bf[i]=x;
    }
    for(int i=1;i<=n;i++){
        if(i==bf[bf[i]]){
            cout << "2" << '\n';
            return;
        }
    }
    cout << "3" << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
}