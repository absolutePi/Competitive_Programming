#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int k=0;k<t;k++){
        int n;
        cin >> n;
        vector<int> v(n),v2(n);
        v.clear();
        for(int i=0;i<n;i++){
            cin >> v[i];
            v2[i] = v[i];
        }
        sort(v2.begin(),v2.end());
        // for(auto i : v2){
        //     cout << i;
        // }
        for(int i=0;i<n;i++){
            if(v[i]==v2[n-1])cout << v[i]-v2[n-2];
            else cout << v[i]-v2[n-1];\
            cout << " ";
        }
        cout << "\n";
    }
}