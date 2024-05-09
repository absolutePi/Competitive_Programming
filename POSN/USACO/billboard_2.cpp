#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);
    int x1,x2,x3,x4,y1,y2,y3,y4,corner=0,ans;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    vector<pair<int,int>> corners;
    corners.push_back({x1,y1});
    corners.push_back({x2,y1});
    corners.push_back({x1,y2});
    corners.push_back({x2,y2});
    for(auto i : corners){
        if(i.first>=x3&&i.first<=x4&&i.second>=y3&&i.second<=y4){
            corner++;
        }
    }
    int x,y;
    if(corner==0||corner==1){ans = (x2-x1)*(y2-y1);}
    else if(corner==2){
        //covered part
        x = min(x4,x2)-max(x3,x1);
        y = min(y4,y2)-max(y3,y1);
        ans = (x2-x1)*(y2-y1) - x*y;
    }
    else if(corner==4){ans=0;}
    cout << ans;
}