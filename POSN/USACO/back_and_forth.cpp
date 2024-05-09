#include <bits/stdc++.h>

using namespace std;

set<int> possibility;

void back_and_forth(int day,int tf,int ts,vector<int> b1,vector<int> b2){
    if(day==4){
        possibility.insert(tf);
        return;
    }
    for(int j=0;j<b1.size();j++){
        int t = b1[j];
        vector<int> newb1 = b1;
        newb1.erase(newb1.begin()+j);
        vector<int> newb2 = b2;
        newb2.push_back(t);
        back_and_forth(day+1,ts+t,tf-t,newb2,newb1);
    }
}

int main(){
    freopen("backforth.in","r",stdin);
    freopen("backforth.out","w",stdout);
    vector<int> buckets1(10),buckets2(10);
    for(int i=0;i<10;i++){
        cin >> buckets1[i];
    }
    for(int i=0;i<10;i++){
        cin >> buckets2[i];
    }
    back_and_forth(0,1000,1000,buckets1,buckets2);
    cout << possibility.size();
}