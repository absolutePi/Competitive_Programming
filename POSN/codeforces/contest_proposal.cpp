#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(auto &i : a)cin >> i;
    for(auto &i : b)cin >> i;
    bool check=true;
    int ind=0;
    while(check){
        check=false;
        for(int i=0;i<n;i++){
            if(b[i]<a[i]){
                check=true;
                a.pop_back();
                a.push_back(b[ind]);
                sort(a.begin(),a.end());
                ind++;
            }
        }
    }
    cout << ind << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)solve();
}