#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
int a[N];

int main(){
    int w,h,n;
    cin >> w >> h >> n;
    for(int i=0;i<n;i++){
        int start,width;
        cin >> start >> width;
        a[start]++;
        a[start+width]--;
    }
    int none=0,half=0;
    for(int i=0;i<w;i++){
        if(i)a[i]+=a[i-1];
        if(a[i]==0)none++;
        else if(a[i]==1)half++;
    }
    // for(int i=0;i<w;i++){
    //     cout << a[i] << ' ';
    // }
    cout << h*none << ' ' << h*half;
}