class Solution {
public:
    int Largest_Rec(vector<int> h){
        int mx=0;
        int n=h.size();
        stack<int> s;
        for(int i=0;i<=n;i++){
            while(!s.empty()&&(i==n||h[s.top()]>=h[i])){
                int height=h[s.top()];
                s.pop();
                int width;
                if(s.empty()){
                    width=i;
                }
                else{
                    width=i-s.top()-1;
                }
                mx=max(mx,height*width);
            }
            s.push(i);
        }
        return mx;
    }

    int solve(vector<vector<char>> mat,int n,int m){
        int ans=0;
        vector<int> height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='1')height[j]++;
                else height[j]=0;
            }
            ans=max(ans,Largest_Rec(height));
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        return solve(matrix,n,m);
    }
};