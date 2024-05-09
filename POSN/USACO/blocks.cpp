#include <bits/stdc++.h>

using namespace std;

vector<int> count_freq(string s){
    vector<int> freq(26);
    for(char c : s){freq[c - 'a']++; }
    return freq;
}
vector<int> mx_block(26);

int main(){
    freopen("blocks.in","r",stdin);
    freopen("blocks.out","w",stdout);
    int n;
    cin >> n;
    vector<pair<string,string>> v(n);
    for(int i=0;i<n;i++){
        string str1,str2;
        cin >> str1 >> str2;
        v[i] = {str1,str2};
    }
    for(int i=0;i<n;i++){
        vector<int> freq1 = count_freq(v[i].first);
        vector<int> freq2 = count_freq(v[i].second);
        for(int c=0;c<26;c++){
            mx_block[c] += max(freq1[c],freq2[c]);
        }
    }
    for(int i=0;i<26;i++){
        cout << mx_block[i] << "\n";
    }
}