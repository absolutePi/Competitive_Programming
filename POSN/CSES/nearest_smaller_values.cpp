#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    stack<int> s;
    for(int i=1;i<=n;i++){
        while(s.size()!=0&&v[s.top()]>=v[i]){
            s.pop();
        }
        if(s.empty()){
            cout << 0 << ' ';
        }
        else{
            cout << s.top() << ' ';
        }
        s.push(i);
    }
}   