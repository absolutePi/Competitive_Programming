#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int total_width,total_height;
        cin >> total_width >> total_height;
        
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int w1 = x2-x1;
        int h1 = y2-y1;

        int w2,h2;
        cin >> w2 >> h2;

        int overlap_left = max(0,w2-x1);
        int overlap_right = max(0,x2-total_width+w2);
        int overlap_top = max(0,y2-total_height+h2);
        int overlap_bottom = max(0,h2-y1);

        if(w1+w2>total_width){
            overlap_left = INT_MAX;
            overlap_right = INT_MAX;
        }

        if(h1+h2>total_height){
            overlap_bottom = INT_MAX;
            overlap_top = INT_MAX;
        }

        int ans = min({overlap_bottom,overlap_left,overlap_right,overlap_top});

        cout << (ans==INT_MAX ? -1 : ans) << endl;
    }
}