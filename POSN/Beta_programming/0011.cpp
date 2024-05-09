#include <bits/stdc++.h>

using namespace std;

const int N = 42;
int arr[N];

int main(){
    for(int i=0;i<10;i++){
        int x;
        cin >> x;
        arr[x%42]++;
    }
    int cnt=0;
    for(int i=0;i<42;i++){
        if(arr[i])cnt++;
    }
    cout << cnt;
}