#include <bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int c,n;
    cin >> c >> n;
    vector<int> teams(n);
    queue<int> q;
    vector<int> dists(1<<c,1000);
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        int x=0;
        int rx=0;
        for(int j=0;j<c;j++){
            //G=1 H=0
            x = x*2 + (str[j]=='G');
            rx = rx*2 + (str[j]=='H');
        }
        teams[i]=x;
        q.push(rx);
        dists[rx]=0;
    }
    while(!q.empty()){
        int curr = q.front();q.pop();
        for(int b=0;b<c;b++){
            int new_curr=curr^(1<<b);
            if(dists[new_curr]==1000){
                dists[new_curr]=dists[curr]+1;
                q.push(new_curr);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << (c-dists[teams[i]]) << endl;
    }
}