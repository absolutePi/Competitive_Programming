#include <bits/stdc++.h>

using namespace std;

string str;
vector<int> v;

int main(){
    cin >> str;
    v.clear();
    int l = str.length();
    for(int i=0;i<l;i++){
        if(str[i]!='+'){
            v.push_back(str[i]-'0');
        }
    }
    l = (l+1)/2;
    sort(v.begin(),v.end());
    for(int i=0;i<l;i++){
        cout << v[i];
        if(i!=l-1){
            cout << "+";
        }
    }
}