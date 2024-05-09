#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,cnt=0;
    cin >> n;
    string str;
    cin >> str;
    char prev = str[0];
    for(int i=1;i<n;i++){
        if(str[i]==prev){
            cnt++;
        }
        prev = str[i];
    }
    cout << cnt;
}