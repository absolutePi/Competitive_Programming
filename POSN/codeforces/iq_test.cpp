#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,e=0,o=0;
    int check=0;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i]%2){
            o++;
        }
        else{
            e++;
        }
    }
    if(e>o){check = 1;}
    for(int i=0;i<n;i++){
        if(arr[i]%2 == check){
            cout << i+1;
            return 0;
        }
    }
}