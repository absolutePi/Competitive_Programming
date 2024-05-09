#include <bits/stdc++.h>

using namespace std;

int main(){
    int num;
    cin >> num;
    if(num == 1){
        cout << 1;
    }
    else if(num < 4){
        cout << "NO SOLUTION";
    }
    else{
        for(int i=2;i<=num;i+=2){
            cout << i << " ";
        }
        for(int i=1;i<=num;i+=2){
            cout << i << " ";
        }
    }
}