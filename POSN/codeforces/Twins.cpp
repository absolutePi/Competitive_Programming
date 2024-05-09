#include <bits/stdc++.h>

using namespace std;

int main(){
    int num,sum1=0,sum2=0,cnt=0;
    cin >> num;
    int arr[num];
    for(int i=0;i<num;i++){
        cin >> arr[i];
        sum1 += arr[i];
    }
    sort(arr,arr+num,greater<int>());
    for(int i=0;i<num;i++){
        sum2+=arr[i];
        cnt++;
        if(sum2>sum1-sum2){
            cout << cnt;
            break;
        }
    }
}