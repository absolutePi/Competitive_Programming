#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,q;
    cin >> t >> q;
    vector<pair<int,int>> v;
    map<vector<pair<int,int>>,int> m;
    for(int i=0;i<t;i++){
        v.clear();
        int n;
        cin >> n;
        for(int i=1;i<n;i++){
            int a,b;
            cin >> a >> b;
            if(a>b)swap(a,b);
            v.push_back({a,b});
        }
        sort(v.begin(),v.end());
        m[v]++;
    }
    for(int i=0;i<q;i++){
        v.clear();
        int n;
        cin >> n;
        for(int i=1;i<n;i++){
            int a,b;
            cin >> a >> b;
            if(a>b)swap(a,b);
            v.push_back({a,b});
        }
        sort(v.begin(),v.end());
        cout << m[v] << '\n';
    }
}