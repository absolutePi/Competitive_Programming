#include <bits/stdc++.h>

using namespace std;

int main(){
    string str1,str2;
    cin >> str1 >> str2;
    for(int i=0;i<str1.length();i++){
        if(str1[i]!=str2[str2.length()-i-1]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}