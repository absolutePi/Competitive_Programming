#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,t;
    cin >> n >> t;
    string str;
    cin >> str;
    int l = str.length();
    vector<int> v;
    while(t--){
        v.assign(l,0);
        for(int i=0;i<l;i++){
            if(str[i]=='B'&&str[i+1]=='G'){
                v[i]++;
                v[i+1]++;
            }
        }
        for(int i=0;i<n;i++){
            if(v[i]==1){
                if(str[i]=='B')str[i]='G';
                else if(str[i]=='G')str[i]='B';
            }
        }
    }
    cout << str;
}