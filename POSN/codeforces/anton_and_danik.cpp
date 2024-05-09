#include <bits/stdc++.h>

using namespace std;

int cntd,cnta;

int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    for(int i=0;i<str.length();i++){
        if(str[i]=='A')cnta++;
        else cntd++;
    }
    if(cntd>cnta)cout << "Danik";
    else if(cnta>cntd)cout << "Anton";
    else cout << "Friendship";
}