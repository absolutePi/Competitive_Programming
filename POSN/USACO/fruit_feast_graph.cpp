#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("feast.in","r",stdin);
    freopen("feast.out","w",stdout);
    int T,A,B;
    cin >> T >> A >> B;
    queue<pair<int,bool>> todo;
    set<pair<int,bool>> did{{0,false}};
    todo.push({0,false});
    while(!todo.empty()){
        pair<int,bool> curr = todo.front();
        todo.pop();
        if(!curr.second){
            if(!did.count({curr.first/2,true})){
                todo.push({curr.first/2,true});
                did.insert({curr.first/2,true});
            }
        }
        for(auto fruit : vector<int>{A,B}){
            int after = curr.first+fruit;
            if(after<=T && !did.count({after,curr.second})){
                todo.push({after,curr.second});
                did.insert({after,curr.second});
            }
        }
    }
    int mx=0;
    for(auto i : did){
        mx=max(mx,i.first);
    }
    cout << mx << '\n';
}   