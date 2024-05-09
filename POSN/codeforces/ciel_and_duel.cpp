#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(A) A.begin(), A.end()
#define pb push_back
#define sz size
#define f first
#define s second

//kill all
int case1(vector<int> atk,vector<int> def,multiset<int> s){
    sort(all(def));
    for(auto i : def){
        auto it = s.upper_bound(i);
        if(it==s.end()){return 0;}
        s.erase(it);
    }
    sort(all(atk));
    int ans=0;
    for(auto i : atk){
        auto it = s.lower_bound(i);
        if(it==s.end()){return 0;}
        ans+=*it-i;
        s.erase(it);
    }
    for(auto i : s){
        ans+=i;
    }
    return ans;
}

//focus on max damage
int case2(vector<int> atk,vector<int> def,multiset<int> s){
    sort(all(atk));
    int ans=0;
    for(auto i : atk){
        if(!s.size()){return ans;}
        auto it = prev(s.end());
        if(*it<=i){break;}
        ans+=*it-i;
        s.erase(it);
    }
    return ans;
}

int main(){
    //ios::sync_with_stdio(false);
    //in.tie(NULL);
    int n,m;
    cin >> n >> m;

    vector<int> atk,def;
    for(int i=0;i<n;i++){
        string str; 
        int x;
        cin >> str >> x;
        if(str=="ATK")atk.pb(x);
        else def.pb(x);
    }
    multiset<int> s;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << max(case1(atk,def,s),case2(atk,def,s));
}