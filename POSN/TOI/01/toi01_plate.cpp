#include <bits/stdc++.h>

using namespace std;

const int Y_NUM=10+5;
const int ID_NUM=1e4+5;
queue<int> qy;
queue<int> qst[Y_NUM];
int st_year[ID_NUM];


int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int years,students;
    cin >> years >> students;
    for(int i=0;i<students;i++){
        int year,id;
        cin >> year >> id;
        st_year[id]=year;
    }
    while(true){
        char t;
        cin >> t;
        if(t=='E'){
            int id;
            cin >> id;
            int curr_year=st_year[id];
            if(qst[curr_year].empty()){
                qy.push(curr_year);
            }
            qst[curr_year].push(id);
        }
        else if(t=='D'){
            if(qy.empty()){cout << "empty" << '\n';}
            else{
                int curr_year=qy.front();
                int curr_id=qst[curr_year].front();
                qst[curr_year].pop();
                if(qst[curr_year].empty()){qy.pop();}
                cout << curr_id << '\n';
            }
        }
        else if(t=='X'){
            cout << "0" << '\n';
            return 0;
        }
    }
}