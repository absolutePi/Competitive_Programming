#include <bits/stdc++.h>

using namespace std;

struct rect{
    int x1,y1,x2,y2;
    int area(){return (x2-x1)*(y2-y1);}
};

rect cut(rect A,rect B){
    //from the left
    if(B.y1<=A.y1&&B.y2>=A.y2&&B.x1<=A.x1&&B.x2>=A.x1){
        A.x1 = B.x2;
        A.x2 = max(A.x2,B.x2);
    }
    //from the top
    if(B.x1<=A.x1&&B.y2>=A.y2&&B.x2>=A.x2&&B.y1<=A.y2){
        A.y2=B.y1;
        A.y1 = min(B.y1,A.y1);
    }
    //from the right
    if(B.y2>=A.y2&&B.y1<=A.y1&&B.x2>=A.x2&&B.x1<=A.x2){
        A.x2=B.x1;
        A.x1 = min(B.x1,A.x1);
    }
    //from the bottom
    if(B.x1<=A.x1&&B.x2>=A.x2&&B.y1<=A.y1&&B.y2>=A.y1){
        A.y1=B.y2;
        A.y2 = max(A.y2,B.y2);
    }
    return A;
}

int main(){
    rect A,B,C;
    cin >> A.x1 >> A.y1 >> A.x2 >> A.y2;
    cin >> B.x1 >> B.y1 >> B.x2 >> B.y2;
    cin >> C.x1 >> C.y1 >> C.x2 >> C.y2;
    A = cut(A,B);
    A = cut(A,C);
    if(A.area()==0)cout << "NO";
    else cout << "YES";
}