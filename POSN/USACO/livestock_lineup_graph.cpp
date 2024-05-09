#include <bits/stdc++.h>

using namespace std;

const int COW_SIZE = 8;
vector<string> cows = {"Beatrice","Belinda","Bella","Bessie","Betsy","Blue","Buttercup","Sue"};

int main(){
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    map<string,int> cow_ind;
    for(int i=0;i<COW_SIZE;i++){
        cow_ind[cows[i]]=i;
    }
    int n;
    cin >> n;
    vector<vector<int>> neighbor(COW_SIZE);
    for(int i=0;i<n;i++){
        string name1,name2,t;
        cin >> name1 >> t >> t >> t >> t >> name2;
        neighbor[cow_ind[name1]].push_back(cow_ind[name2]);
        neighbor[cow_ind[name2]].push_back(cow_ind[name1]);
    }
    vector<bool> added(COW_SIZE,false);
    vector<string> order;
    for(int i=0;i<COW_SIZE;i++){
        if(!added[i]&&neighbor[i].size()<=1){
            added[i]=true;
            order.push_back(cows[i]);
            if(neighbor[i].size()==1){
                int prev = i;
                int at = neighbor[i][0];
                while(neighbor[at].size()==2){
                    added[at]=true;
                    order.push_back(cows[at]);
                    int a = neighbor[at][0];
                    int b = neighbor[at][1];
                    int temp_at = a == prev ? b : a;
                    prev = at;
                    at = temp_at;
                }
                added[at]=true;
                order.push_back(cows[at]);
            }
        }
    }
    for(auto i : order){
        cout << i << endl;
    }
}