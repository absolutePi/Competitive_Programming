#include <bits/stdc++.h>

using namespace std;

int n;
map<char,vector<char>> adj;
map<string,bool> vis;
bool check;

void recur(char node,vector<char> v){
    if(check)return;
    if(v.size()==(n+1)&&!check){
        // cout << "owo";
        check=true;
        for(auto i : v){
            cout << i << ' ';
        }
        return;
    }
    for(auto i : adj[node]){
        string nx,curr;
        nx+=i;
        curr+=node;
        string edge1=nx+curr,edge2=curr+nx;
        if(!vis[edge1]&&!vis[edge2]){
            vis[edge1]=true;
            vis[edge2]=true;
            v.push_back(i);
            recur(i,v);
            v.pop_back();
            vis[edge1]=false;
            vis[edge2]=false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        adj[str[0]].push_back(str[1]);
        adj[str[1]].push_back(str[0]);
    }
    // for(auto i : adj){
    //     cout << i.first << '\n';
    //     for(auto j : i.second){
    //         cout << j << ' ';
    //     }
    //     cout << '\n';
    // }
    char st='A';
    for(auto i : adj){
        if(i.second.size()%2==1){
            st=i.first;
        }
    }
    recur(st,{st});
    // for(auto i : adj){
    //     if(!check){
    //         recur(i.first,{i.first});
    //     }
    // }
}