#include <bits/stdc++.h>

using namespace std;

int main(){
    long long t,total=0;
    cin >> t;
    for(long long b=0;b<t;b++){
        total = 0;
        long long n,m;
        cin >> n >> m;
        vector<vector<long long>> v(n,vector<long long>(m));
        for(long long i=0;i<n;i++){
            for(long long j=0;j<m;j++){
                cin >> v[i][j];
            }
        }
        for(long long j=0;j<m;j++){
            vector<long long> column_mem;
            column_mem.clear();
            long long sum=0,var=0;
            for(long long i=0;i<n;i++){
                column_mem.push_back(v[i][j]);
                sum-=v[i][j];
            }
            sort(column_mem.begin(),column_mem.end(),greater<long long>());
            for(long long i=0;i<n;i++){
                total += sum + column_mem[i]*(n-i);
                sum+=column_mem[i];
            }
        }
        cout << total << "\n";
    }
}