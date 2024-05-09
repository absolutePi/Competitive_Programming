#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<3;j++){
            str[j] = tolower(str[j]);
        }
        if(str=="yes")cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}