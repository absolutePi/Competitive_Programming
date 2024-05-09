#include <bits/stdc++.h>

using namespace std;

int main(){
    int num1,num2,cnt1=1,cnt2=0;;
    cin >> num1 >> num2;
    for(int i=1;i<=num1;i+=2){
        if(cnt1 == num2){
            cout << i;
        }
        cnt1++;
        if(i>=num1&&cnt2==0){
            i=2;
            cnt2++;
        }
    }
}