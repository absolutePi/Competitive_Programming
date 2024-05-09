#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v(3);
    vector<char> alp(3);
    for(int i=0;i<3;i++){
        cin >> v[i];
    }
    for(int i=0;i<3;i++){
        cin >> alp[i];
    }
    sort(v.begin(),v.end());
    for(int i=0;i<3;i++){
        cout << v[alp[i]-'A'] << " ";
    }
}