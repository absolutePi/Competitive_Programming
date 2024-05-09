#include <bits/stdc++.h>

using namespace std;

int main(){
    char last[1];
    int cnt=0,rep=0,max=0;
    string str;
    cin >> str;
    for(int i=0;i<str.length();i++){
        if(cnt == 0){
            last[0]=str[i];
            rep++;
            cnt++;
            if(rep>max){
                max=rep;
            }
        }
        else{
            if(str[i]==last[0]){
                rep++;
                if(rep>max){
                    max=rep;
                }
            }
            else{
                last[0]=str[i];
                if(rep>max){
                    max=rep;
                }
                rep=1;
            }
        }
    }
    cout << max;
}