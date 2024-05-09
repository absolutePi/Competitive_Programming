#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    set<char> s;
    for(int k=0;k<n;k++){
        int m,total=0;
        cin >> m;
        s.clear();
        for(int i=0;i<m;i++){
            char c;
            cin >> c;
            if(s.count(c))total++;
            else{
                total+=2;
                s.insert(c);
            }
        }
        cout << total << "\n";
    }
}