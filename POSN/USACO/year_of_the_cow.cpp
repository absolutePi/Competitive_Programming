#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string, int> yrnumb = {
		{"Ox", 0}, {"Tiger", 1}, {"Rabbit", 2}, {"Dragon", 3},
		{"Snake", 4}, {"Horse", 5}, {"Goat", 6}, {"Monkey", 7},
		{"Rooster", 8}, {"Dog", 9}, {"Pig", 10}, {"Rat", 11}
	};
    
    int n;cin >> n;
    map<string,int> m;
    m["Bessie"]=0;

    for(int i=0;i<n;i++){
        string c1,c2,time,yr,t;
        cin >> c1 >> t >> t >> time >> yr >> t >> t >> c2;

        int age = m[c2],d;
        if (time == "previous") {
			d = -1;
		} else if (time == "next") {
			d = 1;
		}
        do {
			age += d;
		} while ((12 + age % 12) % 12 != yrnumb[yr]);
		m[c1] = age;
    }
    cout << abs(m["Elsie"]);
}