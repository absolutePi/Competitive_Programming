#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cin >> str;
    vector<vector<char>> arr(3,vector<char>(4*str.length()+1,'.'));
    for(int i=0;i<str.length();i++){
        char c;
        if((i+1)%3==0)c='*';
        else c='#';
        arr[0][2+4*i]=c;
        arr[1][1+4*i] = arr[1][3+4*i] = c;
        arr[2][2+4*i]= str[i];
        if(arr[2][0+4*i]=='*')continue;
        else{
            arr[2][0+4*i] = arr[2][4+4*i] = c;
        }
    }
    cout << str.length() << endl << 4*str.length()+1 << endl;
    for(int i=0;i<4*str.length()+1;i++){
        for(int j=0;j<3;j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
    for(int i=1;i>=0;i--){
        for(int j=0;j<3;j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
}