#include <bits/stdc++.h>

using namespace std;

const int N =1e5+1;
int arr1[N],arr2[N];
string str1,str2;

int main(){
    cin >> str1 >> str2;
    int l = str1.length();
    for(int i=0;i<l;i++){
        str1[i]=tolower(str1[i]);
        str2[i]=tolower(str2[i]);
        arr1[i] = str1[i];
        arr2[i] = str2[i];
    }
    // for(int i=0;i<l;i++){
    //     cout << arr1[i] << " ";
    // }
    // cout << "\n";
    // for(int i=0;i<l;i++){
    //     cout << arr2[i] << " ";
    // }
    // cout << l;
    // cout << "\n";
    for(int i=0;i<l;i++){
        if(arr1[i]==arr2[i]){
            continue;
        }
        else if(arr1[i]>arr2[i]){
            cout << "1";
            return 0;
        }
        else if(arr1[i]<arr2[i]){
            cout << "-1";
            return 0;
        }
        // cout << arr1[i] << " " << arr2[i];
    }
    // cout << "\n";
    cout << "0";
    return 0;
}