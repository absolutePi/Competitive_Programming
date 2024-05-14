class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                if(!st.empty()){
                    if(s[st.top()]=='(')st.pop();
                    else{
                        st.push(i);
                    }
                }
                else{
                    st.push(i);
                }
            }
        }
        int longest=0,a=n,b=0;
        if(st.empty())return n;
        else{
            while(!st.empty()){
                b=st.top();st.pop();
                longest=max(longest,a-b-1);
                a=b;
            }
            return max(longest,a);
        }
    }
};