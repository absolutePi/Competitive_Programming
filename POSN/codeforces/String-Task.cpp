#include <bits/stdc++.h>

using namespace std;

int main(){
    bool islowercasevowel,isuppercasevowel;
    string str;
    char newchar;
    getline(cin,str);
    int len = str.length();
    for(int i=0;str[i]!='\0';i++){
        islowercasevowel = (str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='y');
        isuppercasevowel = (str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'||str[i]=='Y');
        if(islowercasevowel || isuppercasevowel){
            continue;
        }
        else{
            if(isupper(str[i])){
                newchar = tolower(str[i]);
                cout << "." << newchar;
            }
            else{
                cout << "." << str[i];
            }
        }
    }
}