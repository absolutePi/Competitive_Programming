#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v1(n),v2(m);
    for(auto &i : v1){cin >> i;}
    for(auto &i : v2){cin >> i;}

    int cnt=0;
    int index = 0;
    for(int i=0;i<m;i++){
        while(v1[index]<v2[i] && index<n){
            cnt++;
            index++;
        }
        cout << cnt << " ";
    }
}