#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<int> pq;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        char c;
        cin >> c;
        if(c=='P'){
            int x;
            cin >> x;
            pq.push(x);
        }
        else if(c=='Q'){
            if(pq.empty()){
                cout << "-1" << '\n';
            }
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
}