#include <bits/stdc++.h>

using namespace std;

int main(){
    map<long long,long long> m;
    long long n;
    cin >> n;
    for(long long i=0;i<n;i++){
        long long a,b,c;
        cin >> a;
        if(a){
            cin >> b;
            cout << m[b] << "\n";
        }
        else{
            cin >> b >> c;
            m[b] = c;
        }
    }
}