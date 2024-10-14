class Solution {
public:
    bool helper(int i,vector<int> &stones,int jump,vector<vector<int>> &dp,unordered_map<int,int> &mp){
        if(i==stones.size()-1) return true;

        if(dp[i][jump] != -1) return dp[i][jump];
        bool flag = false;

        for(int k = -1; k<2; k++){
            int curr = stones[i] + jump + k;
            if(curr>0 && mp.find(curr) != mp.end() && mp[curr] != i){
                flag |= helper(mp[curr], stones, jump+k, dp, mp);
            }
        }
        return dp[i][jump] = flag;
    }
    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp(2010,vector<int>(2010,-1));
        unordered_map<int,int> mp;
        
        for(int i=0; i<stones.size(); i++)
            mp[stones[i]] = i;
        return helper(0, stones, 0, dp, mp);
    }
};