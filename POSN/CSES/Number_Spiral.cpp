#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int num,row,col;
    cin >> num;
    long long int arr[num];
    for(int i=0;i<num;i++){
        cin >> row >> col;
        if(row>=col){
            if(row==1){
                arr[i] = 1;
            }
            else if(row%2==0){
                arr[i] = row*row-(col-1);
            }
            else if(row%2!=0){
                arr[i] = (row-1)*(row-1)+1+(col-1);
            }
        }
        else if(row<col){
            if(col==2){
                arr[i] = 2;
            }
            else if(col%2!=0){
                arr[i] = col*col-(row-1);
            }
            else if(col%2==0){
                arr[i] = (col-1)*(col-1)+(row-1)+1;
            }
        }
    }
    for(int i=0;i<num;i++){
        cout << arr[i] << "\n" ;
    }
}