#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+5;
tuple<int,int,int> arr[N];
bool ans[N];

// bool cmp(const tuple<int,int,int> &a,const tuple<int,int,int> &b){
//     int st1=get<0>(a),st2=get<0>(b);
//     int nd1=get<1>(a),nd2=get<1>(b);
//     if(nd1==nd2)return st1<st2;
//     return nd1<nd2;
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k,m;
    cin >> n >> k >> m;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        arr[i]={a,b,i};
    }
    sort(arr,arr+n);
    // for(int i=0;i<n;i++){
    //     cout << get<0>(arr[i]) << ' ' << get<1>(arr[i]) << ' ' << get<2>(arr[i]) << '\n';
    // }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;//stores end
    // cout << "E";
    for(int i=0;i<n;i++){
        int st=get<0>(arr[i]);
        int nd=get<1>(arr[i]);
        int ind=get<2>(arr[i]);
        // cout << "d";
        while(!q.empty()){
            int fastest_end=q.top().first;
            if(fastest_end<st)q.pop();
            else break;
        }
        if(q.size()<k){
            q.push({nd,ind});
            ans[ind]=true;
        }
        // cout << 'x';
    }
    // cout << "D";
    for(int i=0;i<m;i++){
        int x;
        cin >> x;x--;
        if(ans[x])cout << 'Y';
        else cout << 'N';
        cout << ' ';
    }
}