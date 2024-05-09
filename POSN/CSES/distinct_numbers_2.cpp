#include <bits/stdc++.h>

using namespace std;
    
long long int n,prevn,cnt;

int main(){
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(arr[i]==prevn)continue;
        else{prevn = arr[i];cnt++;}
    }
    cout << cnt;
}