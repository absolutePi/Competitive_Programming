#include <bits/stdc++.h>

using namespace std;

int total;

int main(){
    for(int i=0;i<3;i++){
        int a;
        cin >> a;
        total+=a;
    }
    if(total<=100&&total>=80)cout << "A";
    else if(total>=75)cout << "B+";
    else if(total>=70)cout << "B";
    else if(total>=65)cout << "C+";
    else if(total>=60)cout << "C";
    else if(total>=55)cout << "D+";
    else if(total>=50)cout << "D";
    else cout << "F";
}