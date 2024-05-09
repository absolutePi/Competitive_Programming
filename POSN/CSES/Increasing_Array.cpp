#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int num;
    cin >> num;
    long long int cnt=0;
    long long int arr[num];
    for(int i=0;i<num;i++){
        cin >> arr[i];
    }
    for(int i=1;i<num;i++){
        while(arr[i]<arr[i-1]){
            arr[i]++;
            cnt++;
        }
    }
    cout << cnt;
}