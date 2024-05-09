#include <bits/stdc++.h>

using namespace std;

multiset<int> high,low;
int n,k;

void ins(int x){
    int a=*low.rbegin();
    if(a<x){
        high.insert(x);
        if(high.size()>(k/2)){
            low.insert(*high.begin());
            high.erase(high.find(*high.begin()));
        }
    }
    else{
        low.insert(x);
        if(low.size()>((k+1)/2)){
            high.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    }
}

void er(int x){
    if(high.find(x)!=high.end()){
        high.erase(high.find(x));
    }
    else{
        low.erase(low.find(x));
    }
    if(low.empty()){
        low.insert(*high.begin());
        high.erase(high.find(*high.begin()));
    }
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> k;
    vector<int> v(n);
    for(auto &i : v){cin >> i;}
    low.insert(v[0]);
    for(int i=1;i<k;i++){
        ins(v[i]);
    }
    cout << *low.rbegin() << ' ';
    for(int i=k;i<n;i++){
        if(k==1){
            ins(v[i]);
            er(v[i-k]);
        }
        else{
            er(v[i-k]);
            ins(v[i]);
        }
        cout << *low.rbegin() << ' ';
    }
}