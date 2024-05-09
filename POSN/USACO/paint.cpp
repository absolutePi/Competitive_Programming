#include <bits/stdc++.h>

using namespace std;

const int N =1e5+1;

int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int sum = (b-a) + (d-c);
    int intersect = max(min(b,d) - max(a,c),0);
    cout << sum - intersect;
}