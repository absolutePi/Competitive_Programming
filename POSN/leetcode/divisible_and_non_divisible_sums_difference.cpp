class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num=n/m;
        int sum=(n*(n+1))/2;
        int num2=(num*(num+1))/2*m;
        int num1=sum-num2;
        return num1-num2;
    }
};