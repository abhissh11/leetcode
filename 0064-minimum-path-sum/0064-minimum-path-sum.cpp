class Solution {
public:
int solve( int m, int n, vector<vector<int>> & nums, vector<vector<int>> &dp)
{
    if(m==0 && n==0) {
        return nums[0][0];
    }
    if(m<0 || n<0) return 1e9;

    if (dp[m][n] != -1) return dp[m][n];

    int up = nums[m][n] + solve(m-1, n, nums, dp);
    int left = nums[m][n] + solve(m, n-1, nums, dp);

    dp[m][n] = min(up, left);
    return dp[m][n];
}
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, grid, dp);
    }
};