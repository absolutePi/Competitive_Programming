#include <bits/stdc++.h>

using namespace std;

int n,w,l;

void recur(int curr_win,int curr_lose,vector<char> v){
    if(curr_win==n||curr_lose==n){
        for(auto i : v){
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    v.push_back('W');
    recur(curr_win+1,curr_lose,v);
    v.pop_back();
    v.push_back('L');
    recur(curr_win,curr_lose+1,v);
    return;
}

int main(){
    cin >> n >> w >> l;
    recur(w,l,{});
}