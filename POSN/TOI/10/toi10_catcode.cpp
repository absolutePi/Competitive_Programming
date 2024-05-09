#include <bits/stdc++.h>

using namespace std;

const int MOD=1e6;

int k,m,q,n,hashed[MOD],real_val[MOD];
bool check[MOD];
string str;
//ยังไม่ได้ ซุย
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> k >> m;
    for(int i=1;i<=k;i++){
        cin >> str;
        int curr=0,ind;
        for(int j=0;j<m;j++){
            curr=(curr<<1)+(str[j]-'0');
        }
        ind=curr%MOD;
        while(real_val[ind]!=0){
            ind=(ind+1)%MOD;
        }
        real_val[ind]=i;
        hashed[i]=curr;
    }
    cin >> q;
    while(q--){
        int curr=0;
        cin >> n >> str;
        for(int i=0;i<MOD;i++){
            check[i]=false;
        }
        bool flag=false;
        for(int i=0;i<m-1;i++){
            curr=(curr<<1)+(str[i]-'0');
        }
        for(int i=m-1;i<n;i++){
            curr=(curr<<1)+(str[i]-'0');
            int ind=curr%MOD;
            while(real_val[ind]!=0){
                if(hashed[real_val[ind]]==curr){
                    check[real_val[ind]]=true;
                    flag=true;
                    break;
                }
                ind=(ind+1)%MOD;
            }
            curr-=(curr&(curr<<(m-1)));
        }
        if(flag){
            for(int i=1;i<=k;i++){
                if(check[i]){
                    cout << i << ' ';
                }
            }
            cout << '\n';
        }
        else{
            cout << "OK" << '\n';
        }
    }
}   