#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,x,cnt=0;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    long long int prev;
    for(int i=0;i<n;i++){
        if(cnt==0){
            prev=arr[0];
            cnt++;
        }
        else{
            if(arr[i]==prev){
                continue;
            }
            else{
                cnt++;
                prev=arr[i];
            }
        }
    }
    cout << cnt;
}