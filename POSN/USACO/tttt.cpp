#include <bits/stdc++.h>

using namespace std;

char arr[3][3];
int cnt;
set<int> fs;
set<pair<int,int>> ans;
int z[2];
vector<int> freq(26);
set<char> s;

//my solution(70/100)

int main(){
    freopen("tttt.in","r",stdin);
    freopen("tttt.out","w",stdout);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> arr[i][j];
        }
    }
    //first answer
    char c;
    //horizontally
    for(int i=0;i<3;i++){
        if(arr[i][0]==arr[i][1]&&arr[i][1]==arr[i][2]){
            if(!fs.count(arr[i][0])){
                fs.insert(arr[i][0]);
                cnt++;
            }
        }
    }
    //vectically
    for(int j=0;j<3;j++){
        if(arr[0][j]==arr[1][j]&&arr[1][j]==arr[2][j]){
            if(!fs.count(arr[0][j])){
                fs.insert(arr[0][j]);
                cnt++;
            }
        }
    }
    //diagonally
    if(arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2]){
        if(!fs.count(arr[0][0])){
            fs.insert(arr[0][0]);
            cnt++;
        }
    }
    if(arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0]){
        if(!fs.count(arr[0][2])){
            fs.insert(arr[0][2]);
            cnt++;
        }
    }
    cout << cnt;
    //second answer
    //horizontally
    int temp=0;
    for(int i=0;i<3;i++){
        temp=0;
        s.clear();
        for(int i=0;i<26;i++){
        freq[i]=0;
    }
        cnt=0;
        for(int j=0;j<3;j++){
            if(s.count(arr[i][j]))cnt++;
            else s.insert(arr[i][j]);
        }
        if(cnt==1){
            for(int j=0;j<3;j++){
                freq[arr[i][j]-'A']++;
            }
            for(int j=0;j<26;j++){
                if(freq[j]){
                    z[temp]=j;
                    temp++;
                }
            }
            ans.insert({z[0],z[1]});
        }
    }
    //vectically
    for(int j=0;j<3;j++){
        temp=0;
        s.clear();
        for(int i=0;i<26;i++){
        freq[i]=0;
    }
        cnt=0;
        for(int i=0;i<3;i++){
            if(s.count(arr[i][j]))cnt++;
            else s.insert(arr[i][j]);
        }
        if(cnt==1){
            for(int i=0;i<3;i++){
                freq[arr[i][j]-'A']++;
            }
            for(int i=0;i<26;i++){
                if(freq[i]){
                    z[temp]=i;
                    temp++;
                }
            }
            ans.insert({z[0],z[1]});
        }
    }
    //diagonally left-top to right-bottom
    temp=0;
    s.clear();
    for(int i=0;i<26;i++){
        freq[i]=0;
    }
    cnt=0;
    for(int i=0;i<3;i++){
        if(s.count(arr[i][i]))cnt++;
        else s.insert(arr[i][i]);
    }
    if(cnt==1){
        for(int i=0;i<3;i++){
            freq[arr[i][i]-'A']++;
        }
        for(int j=0;j<26;j++){
            if(freq[j]){
                z[temp]=j;
                temp++;
            }
        }
        ans.insert({z[0],z[1]});
     }
     //diagonally right-top to left-bottom
    temp=0;
    s.clear();
    for(int i=0;i<26;i++){
        freq[i]=0;
    }
    cnt=0;
    for(int i=0;i<3;i++){
        if(s.count(arr[i][2-i]))cnt++;
        else s.insert(arr[i][2-i]);
    }
    if(cnt==1){
        for(int j=0;j<3;j++){
            freq[arr[j][2-j]-'A']++;
        }
        for(int j=0;j<26;j++){
            if(freq[j]){
                z[temp]=j;
                temp++;
            }
        }
        ans.insert({z[0],z[1]});
     }
    cout << "\n" << ans.size();
}