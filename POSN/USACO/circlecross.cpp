#include <bits/stdc++.h>

using namespace std;

int arr[26];

int main(){
    freopen("circlecross.in","r",stdin);
    freopen("circlecross.out","w",stdout);
    int cnt=0;
    string str;
    cin >> str;
    set<char> visited;
    for(int i=0;i<52;i++){
        if(!visited.count(str[i])){
            for(int j=0;j<26;j++){
                arr[j]=0;
            }
            for(int j=i+1;j<52;j++){
                if(str[i]==str[j]){break;}
                else{
                    arr[str[j]-'A']++;
                }
            }
            for(int j=0;j<26;j++){
                if(arr[j]==1)cnt++;
            }
            visited.insert(str[i]);
        }
    }
    cout << cnt/2;
}