#include <bits/stdc++.h>

using namespace std;

const int N =1e5+1;
int chess[N],white,black;

void check(char c){
    if(c == 'k')return;
    if(c>=65 && c<=90){
        white+=chess[tolower(c)];
    }
    else if(c>=97 && c<=122){
        black+=chess[c];
    }
    return;
}

int main(){
    chess['n']=3,chess['r']=5,chess['b']=3,chess['p']=1,chess['q']=9;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            char x;
            cin >> x;
            check(x);
        }
    }
    if(white>black){cout << "White";}
    else if(black>white){cout << "Black";}
    else cout << "Draw";
}