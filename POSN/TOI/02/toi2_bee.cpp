#include <bits/stdc++.h>

using namespace std;

pair<int,int> ans[25];//{ngan,sum}

int main(){
    int ngan=1,soldier=0;
    for(int i=1;i<=24;i++){
        int old_ngan=ngan;
        int old_soldier=soldier;
        ngan++;//queen
        ngan+=soldier;
        soldier=old_ngan;
        ans[i]={ngan,ngan+soldier+1};
    }
    while(true){
        int x;
        cin >> x;
        if(x==-1)break;
        cout << ans[x].first << ' ' << ans[x].second << '\n';
    }
}