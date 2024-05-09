#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> city(n),cel(m);
    for(auto &i : city){cin >> i;}
    for(auto &i : cel){cin >> i;}

    int ptr_city=0;
    int ptr_cel=0;
    int mx=0;
    while(ptr_city<n){
        while(abs(city[ptr_city]-cel[ptr_cel])>=abs(city[ptr_city]-cel[ptr_cel+1])&& ptr_cel<m-1){
            ptr_cel++;
        }
        mx = max(mx,abs(city[ptr_city]-cel[ptr_cel]));
        ptr_city++;
    }
    cout << mx;
}