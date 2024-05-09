#include <bits/stdc++.h>

using namespace std;

int n;
string str;

bool check(int i){
    for(int j=0;j<n-i;j++){
        if(str[j]!=str[j+i]){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> n >> str;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            if(check(i)){
                cout << i << '\n';
                return 0;
            }
        }
    }    
}