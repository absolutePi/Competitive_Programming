#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    bool cp=0,sm=0;
    cin >> str;
    for(int i=0;i<str.length();i++){
        if(str[i]>=97&&str[i]<=122)sm=1;
        else if(str[i]>=65&&str[i]<=90)cp=1;
        if(cp&&sm){
            cout << "Mix";
            return 0;
        }
    }
    if(cp)cout << "All Capital Letter";
    else cout << "All Small Letter";
}