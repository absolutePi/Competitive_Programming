#include <bits/stdc++.h>

using namespace std;

int cntu,cntl;

int main(){
    string str;
    cin >> str;
    for(int i=0;i<str.length();i++){
        if(str[i]>=65&&str[i]<=90)cntu++;
        if(str[i]>=97&&str[i]<=122)cntl++;
    }
    if(cntu>cntl){
        for(int i=0;i<str.length();i++){
            str[i] = toupper(str[i]);
        }
    }
    else{
        for(int i=0;i<str.length();i++){
            str[i] = tolower(str[i]);
        }
    }
    cout << str;
}