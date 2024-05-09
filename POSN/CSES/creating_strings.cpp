#include <bits/stdc++.h>

using namespace std;

string str;
int avb_char[26];
vector<string> perm;

void func(string curr = ""){
    if(curr.length()==str.length()){
        perm.push_back(curr);
    }
    for(int i=0;i<26;i++){
        if(avb_char[i]>0){
            avb_char[i]--;
            func(curr+char(i+'a'));
            avb_char[i]++;
        }
    }
}

int main(){
    cin >> str;
    for(int i=0;i<str.length();i++){
        avb_char[str[i]-'a']++;
    }
    func();
    cout << perm.size() << "\n";
    for(auto i : perm){
        cout << i << "\n";
    }
}