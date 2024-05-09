#include <bits/stdc++.h>

using namespace std;

int main(){
    int cnt=0;
    string str;
    getline(cin,str);
    int len = str.length();
    for(int i=0;i<len;i++){
        if(str[i]=='H'||str[i]=='Q'||str[i]=='9'){
            cnt++;
        }
    }
    if(cnt==0){
        cout << "NO";
    }
    else{
        cout << "YES";
    }
}