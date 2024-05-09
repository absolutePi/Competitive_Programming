#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+1;
string str[N];

int main(){
    freopen("cownomics.in","r",stdin);
    freopen("cownomics.outZ","w",stdout);
    int n,l,ans=0;
    cin >> n >> l;
    for(int i=0;i<n*2;i++){
        cin >> str[i];
    }
    vector<char> c;
    for(int j=0;j<l;j++){
        bool check = true;
        c.clear();
        for(int i=0;i<n;i++){
            c.push_back(str[i][j]);
        }
        for(int i=n;i<n*2;i++){
            for(auto t : c){
                if(str[i][j]==t){
                    goto jump;
                }
            }
        }
        ans++;
        jump: continue;
    }
    cout << ans;
}