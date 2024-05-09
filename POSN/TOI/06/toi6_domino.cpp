#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<pair<char,char>>> ans;

void recur(int curr_row,vector<pair<char,char>> curr){
    if(curr_row==n){
        ans.push_back(curr);
        return;
    }
    curr.push_back({'-','-'});
    recur(curr_row+1,curr);
    curr.pop_back();
    if(curr_row+1<n){
        curr.push_back({'|','|'});
        recur(curr_row+2,curr);
        curr.pop_back();
    }
    return;
}

int main(){
    cin >> n;
    recur(0,{});
    for(auto i : ans){
        for(auto j : i){
            cout << j.first << j.second << '\n';
        }
        cout << 'E' << '\n';
    }
}   