#include <bits/stdc++.h>

using namespace std;

int main(){
    int num,x=0,y=0,z=0;
    cin >> num;
    int arr[num][3];
    for(int i=0;i<num;i++){
        for(int j=0;j<3;j++){
            cin >> arr[i][j];
            if(j==0){
                x+=arr[i][j];
            }
            else if(j==1){
                y+=arr[i][j];
            }
            else if(j==2){
                z+=arr[i][j];
            }
        }
    }
    if(x!=0||y!=0||z!=0){
        cout << "NO";
    }
    else{
        cout << "YES";
    }
}