#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int x=0;x<t;x++){
        vector<int> v;
        v.clear();
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        for(int i=0;i<n;i++){
            if(i==0){
                v.push_back(arr[i]);
            }
            else{
                if(arr[i]>=arr[i-1]){
                    v.push_back(arr[i]);
                }
                else{
                    v.push_back(arr[i]);
                    v.push_back(arr[i]);
                }
            }
        }
        cout << v.size() << "\n";
        for(auto i : v){cout << i << " ";}
        puts("");
    }
}