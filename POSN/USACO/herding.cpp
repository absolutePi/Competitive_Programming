#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("herding.in","r",stdin);
    freopen("herding.out","w",stdout);
    int a,b,c;
    cin >> a >> b >> c;
    int x = b-a-1,y = c-b-1;
    if(x==0&&y==0){
        cout << "0";
    }
    else if(x==1 || y==1){
        cout << "1";
    }
    else cout << "2";
    cout << "\n" << max(x,y);
}