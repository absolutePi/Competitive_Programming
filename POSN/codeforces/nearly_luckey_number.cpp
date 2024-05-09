#include <bits/stdc++.h>

using namespace std;

int cnt;

int main(){
    string str;
    cin >> str;
    int l = str.length();
    for(int i=0;i<l;i++){
        if(str[i]=='4'||str[i]=='7'){
            cnt++;
        }
    }
    string result = (cnt==4||cnt==7) ? "YES" : "NO";
    cout << result;
}