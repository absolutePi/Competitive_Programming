#include <bits/stdc++.h>

using namespace std;

int power[10];

int move(int curr,int ind1,int ind2){
    int a = curr%power[ind1+1]/power[ind1];
    int b = curr%power[ind2+1]/power[ind2];
    return curr-a*power[ind1]-b*power[ind2]+a*power[ind2]+b*power[ind1];
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    power[0]=1;
    for(int i=1;i<10;i++){power[i]=power[i-1]*9;}
    vector<bool> vis(power[9]);
    int target=0;
    for(int i=8;i>=0;i--){
        target+=(8-i)*power[i];
    }
    int grid=0;
    for(int i=8;i>=0;i--){
        int num;
        cin >> num;
        grid+=(num-1)*power[i];
    }
    queue<pair<int,int>> q;//situation and distance
    q.push({grid,0});
    while(!q.empty()){
        int g,dist;
        tie(g,dist)=q.front();
        q.pop();
        if(g==target){
            cout << dist << '\n';
            return 0;
        }
        for(int i=0;i<6;i++){//vertically
            int swapped = move(g,i,i+3);
            if(!vis[swapped]){
                vis[swapped]=true;
                q.push({swapped,dist+1});
            }
        }
        for(int i=0;i<8;i++){//horizontally
            int swapped = move(g,i,i+1);
            if(i%3==2){continue;}
            if(!vis[swapped]){
                vis[swapped]=true;
                q.push({swapped,dist+1});
            }
        }
    }
}   