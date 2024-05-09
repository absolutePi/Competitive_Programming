#include <bits/stdc++.h>

using namespace std;

int main(){
    double a,b,c;
    cin >> a >> b;
    a*=a;b*=b;
    c = sqrt(a+b);
    printf("%.6lf",c);
}