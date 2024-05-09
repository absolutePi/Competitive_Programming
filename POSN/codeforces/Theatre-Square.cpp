#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int n,m,a;
    cin >> n >> m >> a;
    long long int area1=n*m;
    long long int area2=a*a;
    if(area2>=area1){
        cout << "1";
    }
    else if(area1%area2==0){
        if((area1/area2)%2!=0){
            cout << area1/area2 +1;
        }
        else{
            cout << area1/area2;
        }
    }
    else{
        if((area1/area2 + 1)%2!=0){
            cout << area1/area2 +2;
        }
        else{
        cout << area1/area2 + 1;
        }
    }
}