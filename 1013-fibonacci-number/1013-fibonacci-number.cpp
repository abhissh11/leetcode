class Solution {
    int func(vector<int> &dp, int n){
        if(dp[n]!= -1) return dp[n];
        dp[n] = func(dp, n-1) + func(dp, n-2);
        return dp[n];
    }
public:
    int fib(int n) {
        if(!n) return 0;
        if(n == 1) return 1;
        vector<int> dp(n+1, -1);       // initialize an arr of n+1 size and put -1 each elm
        dp[0] = 0;
        dp[1] = 1;

        return func(dp, n);
    }
};