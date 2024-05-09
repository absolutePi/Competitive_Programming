#include <bits/stdc++.h>

using namespace std;

string origin,op,ans;
vector<vector<int>> v(3,{0,1,2,3,4,5,6,7,8});

void rotate(vector<int> &v,int n){
    while(n--){
        v.push_back(v[0]);
        v.erase(v.begin());
    }
}

int main(){
    cin >> origin;
    for(int i=0;i<3;i++){
        // char c;
        // cin >> c;
        // origin[i]=c-'0';
        rotate(v[i],origin[i]-'1');
    }
    cin >> op;
    for(auto i : op){
        ans.push_back((v[2][v[1][v[0][i-'1']]]+1)+'0');
        rotate(v[0],origin[0]);
        rotate(v[2],origin[2]);
        v[1].insert(v[1].begin(),v[1][8]);
        v[1].pop_back();
    }
    cout << ans << '\n';
}