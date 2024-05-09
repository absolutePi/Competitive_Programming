#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool cmp(const string &a,const string &b){
    return (a+b)<(b+a);
}

int main(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(string &s : v){
        cin >> s;
    }
    sort(v.begin(),v.end(),cmp);
    for(const string &s : v){
        cout << s;
    }
}