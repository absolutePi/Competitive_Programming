#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
int a[N];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int l,h,r;
        cin >> l >> h >> r;
        for(int j=l;j<r;j++){
            a[j]=max(a[j],h);
        }
    }
    for(int i=1;i<N;i++){
        if(a[i-1]!=a[i]){
            cout << i << ' ' << a[i] << ' ';
        }
    }
}