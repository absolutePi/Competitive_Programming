#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    int n;
    cin >> n;
    vector<pair<string,string>> conditions;
    for(int i=0;i<n;i++){
        string str1,str2,t;
        cin >> str1;
        cin >> t >> t >> t >> t;
        cin >> str2;
        conditions.push_back({str1,str2});
    }
    vector<string> cows{"Bessie","Buttercup","Belinda","Beatrice","Bella","Blue","Betsy","Sue"};
    sort(cows.begin(),cows.end());
    while(next_permutation(cows.begin(),cows.end())){
        bool passed = true;
        for(auto i : conditions){
            string cow1 = i.first;
            string cow2 = i.second;
            auto a = find(cows.begin(),cows.end(),cow1);
            auto b = find(cows.begin(),cows.end(),cow2);
            if(abs(a-b)!=1){
                passed = false;
            }
        }
        if(passed){
            break;
        }
    }
    for(auto i : cows){
        cout << i << endl;
    }
}