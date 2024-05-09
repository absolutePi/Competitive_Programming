#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n,temp=1,cnt=0;
        vector<int> v;
        cin >> n;
        while(n){
            int x = (n%10)*temp;
            if(x!=0){v.push_back((n%10)*temp);}
            temp*=10;
            n/=10;
        }
        cout << (int)v.size() << endl;
        for(auto i : v){
            cout << i << " ";
        }
        cout << endl;
    }
}