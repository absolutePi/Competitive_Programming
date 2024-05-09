#include <bits/stdc++.h>

using namespace std;

int k;
string ad;
vector<int> word_lengths;

bool works(int width){
    int curr_width=0;
    int lines=1;
    for(auto length : word_lengths){
        if(length>width){
            return false;
        }
        if(curr_width+length>width){
            lines++;
            curr_width=length;
        }
        else{
            curr_width+=length;
        }
    }
    return lines<=k;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> k;
    cin.ignore();
    getline(cin,ad);
    word_lengths.push_back(0);
    for(auto i : ad){
        word_lengths.back()++;
        if(i==' ' || i=='-'){
            word_lengths.push_back(0);
        }
    }
    int l=0,r=ad.size(),mid;
    r++;
    while(l<r){
        mid = l+(r-l)/2;
        if(works(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout << l << endl;
}       