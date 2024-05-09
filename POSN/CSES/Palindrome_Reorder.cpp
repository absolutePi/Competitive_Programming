#include <bits/stdc++.h>

using namespace std;

int arr[26];

int main(){
    int k;
    string str;
    getline(cin,str);
    int l = str.length();
    int cnt=0;
    for(int i=0;i<l;i++){
        arr[str[i]-65]++;
    }
    for(int i=0;i<26;i++){
        if(arr[i]==1){
            cnt++;
            k=i;
        }
    }
    if(l%2){
        if(cnt==1){
            for(int i=0;i<26;i++){
                if(arr[i]>0){
                    for(int j=0;j<arr[i]/2;j++){
                        printf("%c",65+i);
                    }
                }
            }
            printf("%c",65+k);
            for(int i=25;i>=0;i--){
                if(arr[i]>0){
                    for(int j=0;j<arr[i]/2;j++){
                        printf("%c",65+i);
                    }
                }
            }
        }
        else if(cnt>1){
            cout << "NO SOLUTION";
        }
    }
    else{
        if(cnt>=1){
            cout << "NO SOLUTION";
        }
        else{
            for(int i=0;i<26;i++){
                if(arr[i]>0){
                    for(int j=0;j<arr[i]/2;j++){
                        printf("%c",65+i);
                    }
                }
            }
            for(int i=25;i>=0;i--){
                if(arr[i]>0){
                    for(int j=0;j<arr[i]/2;j++){
                        printf("%c",65+i);
                    }
                }
            }
        }
    }
}