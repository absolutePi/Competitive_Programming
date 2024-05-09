#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int k=0;k<t;k++){
        vector<int> v;
        v.clear();
        set<int> s;
        s.clear();
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        bool check = false;
        for(int i=n-1;i>=0;i--){
            if(s.count(v[i])){
                cout << i+1;
                check = true;
                break;
            }
            else s.insert(v[i]);
        }
        if(!check){
            cout << "0";
        }
        cout << "\n";
    }
}