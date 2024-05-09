#include <bits/stdc++.h>

using namespace std;

int x,y,cnt=0,sw = 0;

int main(){
    freopen("lostcow.in","r",stdin);
    freopen("lostcow.out","w",stdout);
    cin >> x >> y;
    int pos = x;
    for(int i=1 ; i>0 ; i*=2){
        sw++;
        int oldpos = pos;
        if(sw%2){
            pos = x + i;
            for(int j=oldpos ; j<pos ; j++){
                if(j==y){
                    goto jump;
                }
                cnt++;
            }
        }
        else{
            pos = x - i;
            for(int j=oldpos ; j>pos ; j--){
                if(j==y){
                    goto jump;
                }
                cnt++;
            }
        }
        // cout << sw << " " << pos << " " << oldpos << "\n";
    }
    jump:
    cout << cnt;
}