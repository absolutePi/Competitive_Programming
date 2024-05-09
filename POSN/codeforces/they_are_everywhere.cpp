#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    unordered_set<char> target;
    string str;
    cin >> str;
    for(int i=0;i<n;i++){
        target.insert(str[i]);
    }

    int mn=INT_MAX;
    int left=0;
    unordered_map<char,int> curr;
    for(int right=0;right<n;right++){
        curr[str[right]]++;
        while(left+1<=right && curr.count(str[left]) && curr[str[left]]>1){
            curr[str[left]]--;
            left++;
        }
        if(curr.size()==target.size()){
            mn = min(mn,right-left+1);
        }
    }    
    cout << mn;
}