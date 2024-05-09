#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+1;
int shuf[N];
vector<int> id,stdid;

int main(){
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> shuf[i];
    }
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        id.push_back(x);
    }
    for(int i=0;i<3;i++){
        stdid = id;
        for(int j=0;j<n;j++){
            id[j] = stdid[shuf[j]-1];
        }
    }
    for(auto i : id){
        cout << i << "\n";
    }
}