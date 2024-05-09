#include <bits/stdc++.h>

using namespace std;

int main(){
    set<string> s;
    map<string,int> m;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        if(s.count(str)){
            m[str]++;
            cout << str << m[str] << "\n";
            s.insert(str+to_string(m[str]));
            m[str+to_string(m[str])] = 0; 
            // cout << str+to_string(m[str]);
        }
        else{
            s.insert(str);
            m[str]=0;
            cout << "OK" << "\n";
        }
    }
}
