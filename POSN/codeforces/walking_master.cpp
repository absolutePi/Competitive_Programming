#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        for(int i=0;i<4;i++){
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            while(a!=c&&b!=d){
                if(a>c){
                    a--;
                }
                if(b<d){
                    a++;
                    b++;
                }
            }
        }
    }
}