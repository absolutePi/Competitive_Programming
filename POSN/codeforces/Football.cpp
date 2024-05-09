#include <bits/stdc++.h>

using namespace std;

int main(){
    int cnt1=0,cnt2=0;
    string str;
    getline(cin,str);
    int len = str.length();
    for(int i=0;i<len;i++){
        cnt1d=0;
        for(int j=i;j<len;j++){
            if(str[i]==str[j]){
                cnt1++;
            }
            else{
                break;
            }
        }
        if(cnt1>=7){
            cnt2++;
        }
    }
    if(cnt2>0){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}