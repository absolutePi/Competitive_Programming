#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,cnt=0;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                cnt++;
            }
        }
    }
    cout << "Array is sorted in " << cnt << " swaps.\nFirst Element: " << arr[0] << "\nLast Element: " << arr[n-1];

}