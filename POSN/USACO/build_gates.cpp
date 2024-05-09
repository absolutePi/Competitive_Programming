#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("gates.in","r",stdin);
    freopen("gates.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int l;
    cin >> l;
    string str;
    cin >> str;

    set<pair<pair<int,int>,pair<int,int>>> visedge;
    set<pair<int,int>> visnode;
    int ans=0;
    pair<int,int> prev={0,0};
    visnode.insert({0,0});

    for(int i=0;i<l;i++){
        int x=prev.first;
        int y=prev.second;
        if(str[i]=='N'){
            x++;
        }
        else if(str[i]=='E'){
            y++;
        }
        else if(str[i]=='S'){
            x--;
        }
        else{
            y--;
        }
        if(visedge.find({prev,{x,y}})==visedge.end()&&
        visnode.find({x,y})!=visnode.end()){
            ans++;
        }
        visedge.insert({prev,{x,y}});
        visedge.insert({{x,y},prev});
        visnode.insert({x,y});
        prev.first=x;
        prev.second=y;
    }
    cout << ans << endl;
}   