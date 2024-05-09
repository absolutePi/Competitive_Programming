#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("whereami.in","r",stdin);
    freopen("whereami.out","w",stdout);
    bool check = false;
    int n;
    cin >> n;
    string str;
    cin >> str;
    int l=1,r=str.length(),mid = (l+r)/2;
    set<string> s;
    while(l<r){
        s.clear();
        check = false;
        mid = (l+r)/2;
        for(int i=0;i<n-mid+1;i++){
            if(s.count(str.substr(i,mid))){
                l = mid+1;
                check = true;
                break;
            }
            s.insert(str.substr(i,mid));
        }
        if(!check){
            r = mid;
        }
    }
    cout << r;
}