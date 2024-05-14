class Solution {
public:
    string defangIPaddr(string str) {
        int n=str.length();
        string ans;
        for(int i=0;i<n;i++){
            if(str[i]=='.'){
                ans=ans+"[.]";
            }
            else ans=ans+str[i];
        }
        return ans;
    }
};