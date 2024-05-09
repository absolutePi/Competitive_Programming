#include <bits/stdc++.h>

using namespace std;

const int N =1e5+1;
int arr[N],cnt;
string str;

int main(){
    cin >> str;
    int l = str.length();
    for(int i=0;i<l;i++){
        arr[str[i]] = 1;
    }
    for(int i=97;i<=122;i++){
        if(arr[i]){
            cnt++;
        }
    }
    if(cnt%2){
        cout << "IGNORE HIM!";
    }
    else{
        cout << "CHAT WITH HER!";
    }
}