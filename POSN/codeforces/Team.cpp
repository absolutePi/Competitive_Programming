#include <bits/stdc++.h>

using namespace std;

int main(){
    int num,solve = 0;
    cin >> num;
    int arr[num][3];
    for(int i=0;i<num;i++){
        for(int j=0;j<3;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<num;i++){
        int cnt=0;
        for(int j=0;j<3;j++){
            if(arr[i][j]==1){
                cnt++;
            }
        }
        if(cnt>=2){
            solve++;
        }
    }
    cout << solve;
}