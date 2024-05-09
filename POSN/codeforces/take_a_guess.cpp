#include <bits/stdc++.h>

using namespace std;

int ask(string str,int a,int b){
    cout << str << ' ' << a << ' ' << b << endl;
    int res;
    cin >> res;
    return res;
}

int sum(int a,int b){
    int _and = ask("and",++a,++b);
    int _or = ask("or",a,b);
    int _xor = ~(_and)&(_or);
    return 2*(_and)+_xor;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n,k;
    cin >> n >> k;
    int a_plus_b = sum(0,1);
    int a_plus_c = sum(0,2);
    int b_plus_c = sum(1,2);
    vector<int> arr{(a_plus_b+a_plus_c-b_plus_c)/2};
    arr.push_back(a_plus_b-arr[0]);
    arr.push_back(a_plus_c-arr[0]);
    for(int i=3;i<n;i++){
        arr.push_back(sum(i-1,i)-arr.back());
    }
    sort(arr.begin(),arr.end()); 
    cout << "finish " << arr[k-1] << endl;
}