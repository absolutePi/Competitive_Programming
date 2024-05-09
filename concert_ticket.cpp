#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

int main(){
    int t,c;
    cin >> t >> c;
    multiset<int> tic;
    vector<int> cus(c);
    for(int i=0;i<t;i++){
        int x;
        cin >> x;
        tic.insert(x);
    }
    for(auto &i : cus){cin >> i;}
    for(int i=0;i<c;i++){
        auto it = tic.lower_bound(cus[i]);
        if(*it == cus[i]){
            cout << *it << endl;
            tic.erase(tic.find(*it));
        }
        else{
            if(it==tic.begin()&&*it>cus[i] || tic.size()==0){
                cout << "-1" << endl;
            }
            else{
                it--;
                cout << *it << endl;
                tic.erase(tic.find(*it));
            }
        }
    }
}