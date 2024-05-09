#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<double,double>> v(n);
    for(int i=0;i<n;i++){
        double price,amnt;
        cin >> price >> amnt;
        v[i]={price/amnt,amnt};
    }
    sort(v.begin(),v.end());//price amount
    // for(auto i : v){
    //     cout << i.first << ' ' << i.second << '\n';
    // }
    int q,ind=0;
    cin >> q;
    while(q--){
        double x,curr=0;
        cin >> x;
        while(x&&(ind<n)){
            double price=v[ind].first;
            double amt=v[ind].second;
            double buying=min(x,amt);
            curr+=buying*price;
            v[ind].second-=buying;
            x-=buying;
            if(v[ind].second==0)ind++;
        }
        cout << fixed << setprecision(3) << curr << '\n';
    }
}