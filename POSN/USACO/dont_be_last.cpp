#include <bits/stdc++.h>

using namespace std;

string arr[7] = {"Bessie","Elsie","Daisy","Gertie","Annabelle","Maggie","Henrietta"};

int main(){
    freopen("notlast.in","r",stdin);
    freopen("notlast.out","w",stdout);
    map<string,int> productions;
    for(int i=0;i<7;i++){
        productions[arr[i]]=0;
    }
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string name;
        int milk;
        cin >> name >> milk;
        productions[name]+=milk;
    }
    vector<pair<int,string>> v;
    for(int i=0;i<7;i++){
        v.push_back({productions[arr[i]],arr[i]});
    }
    sort(v.begin(),v.end());
    int mn = v[0].first,ans;
    string name;
    for(int i=0;i<7;i++){
        if(v[i].first>mn){
            ans = v[i].first;
            name = v[i].second;
            break;
        }
    }
    int cnt=0;
    for(int i=0;i<7;i++){
        if(v[i].first==ans){
            cnt++;
        }
    }
    if(cnt>1)cout << "Tie" << endl;
    else cout << name << endl;
}