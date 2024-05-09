#include <bits/stdc++.h>

using namespace std;

int n;
/*
การเรียงก่อนหลังของการแสดงเส้นทางเชื่อม ไม่มีผลต่อความถูกต้อง
ในการตรวจสอบผลลัพธ์ ??????????
*/
void recur(int length,string curr){
    if(length==n){
        for(int i=n-1;i>=0;i--){
            if(curr[i]=='0'){
                string str=curr;
                str[i]='1';
                cout << curr << ' ' << str << '\n';
            }
        }
    }
    else{
        recur(length+1,curr+"0");
        recur(length+1,curr+"1");
    }
}

int main(){
    cin >> n;
    recur(0,"");
}