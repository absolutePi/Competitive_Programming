#include <bits/stdc++.h>

using namespace std;

int main(){
    int num,x=0;
    cin >> num;
    char chr[3];
    for(int i=0;i<num;i++){
        int cnt = 0;
        for(int j=0;j<3;j++){
            cin >> chr[j];
            if(chr[j]== '+'&&cnt==0){
                x++;
                cnt++;
            }
            else if(chr[j]== '-'&&cnt==0){
                x--;
                cnt++;
            }
        }
    }
    cout << x;
}