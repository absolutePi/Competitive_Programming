#include <bits/stdc++.h>

using namespace std;

const int N = 3;
const int TURN_NUM = 100;

int main(){
    freopen("mixmilk.in","r",stdin);
    vector<int> cap(N);
    vector<int> cur(N);
    for(int i=0;i<N;i++){
        scanf("%d %d",&cap[i],&cur[i]);
    }
    for(int i=0;i<TURN_NUM;i++){
        int bucket1 = i%N;
        int bucket2 = (i+1)%N;
        int pour = min(cur[bucket1],cap[bucket2]-cur[bucket2]);
        cur[bucket1]-=pour;
        cur[bucket2]+=pour;
    }
    freopen("mixmilk.out","w",stdout);
    for(auto i : cur){
        cout << i << "\n";
    }
}