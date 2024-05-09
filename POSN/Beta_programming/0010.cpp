#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cin >> str;
    vector<int> v{1,0,0};   
    for(int i=0;i<str.length();i++){
        if(str[i]=='A')swap(v[0],v[1]);
        if(str[i]=='B')swap(v[1],v[2]);
        if(str[i]=='C')swap(v[0],v[2]);
    }
    for(int i=0;i<3;i++){
        if(v[i]==1){
            cout << i+1;
        }
    }
}