#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

void solve(){
    int l1,l2;
    cin >> l1 >> l2;
    string str1,str2;
    cin >> str1 >> str2;
    int cnt=0;
    while(l2--){
        bool isFound = str1.find(str2) != string::npos;
        if(isFound){
            cout << cnt << endl;
            return;
        }
        str1.append(str1);
        cnt++;
    }
    cout << "-1" << endl;
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}