#include <bits/stdc++.h>

using namespace std;

string str1,str2;
int l,cnt=0;

int main(){
    freopen("breedflip.in","r",stdin);
    freopen("breedflip.out","w",stdout);
    cin >> l;
    cin >> str1 >> str2;
    bool check = false;
    for(int i=0;i<l;i++){
        if(str1[i]!=str2[i]){
            if(!check){
                cnt++;
                check = true;
            }
        }
        else{
            check = false;
        }
    }
    cout << cnt;
}