#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> salary(n);
    vector<int> banks(m);
    for(auto &i : salary){cin >> i;}
    for(auto &i : banks){cin >> i;}
    vector<int> covered(1<<m,-1);
    vector<int> left_over(1<<m,-1);
    covered[0]=0;
    left_over[0]=0;
    for(int mask=1;mask<(1<<m);mask++){
        for(int b=0;b<m;b++){
            if(mask&(1<<b)){
                int prev=mask^(1<<b);
                if(covered[prev]!=-1){
                    int target=salary[covered[prev]];
                    int money=left_over[prev]+banks[b];
                    if(money<target){
                        covered[mask]=covered[prev];
                        left_over[mask]=money;
                    }
                    else if(money==target){
                        covered[mask]=covered[prev]+1;
                        left_over[mask]=0;
                    }
                }
            }
        }
        if(covered[mask]==n){
            cout << "YES" << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
}       