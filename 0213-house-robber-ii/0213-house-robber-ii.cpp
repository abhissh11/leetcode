class Solution {
public:
   int solve(vector<int>&nums,int index,int lastindex,vector<int>&dp){
       if(index>lastindex){
        return 0;
       }

       if(dp[index]!=-1){
            return dp[index];
       }
       
       //exlude
       int leave=0+solve(nums,index+1,lastindex,dp);

       //include
       int rob=nums[index]+solve(nums,index+2,lastindex,dp);
       dp[index]=max(leave,rob);
       
       return dp[index];
 }

    int rob(vector<int>& nums) {
      int n=nums.size();

      if(n==1){  //yha pr humne glti ki thi
        return nums[0];
      }

    vector<int>dp1(n+1,-1);
    vector<int>dp2(n+1,-1);

    int case1=solve(nums,0,n-2,dp1);
    int case2=solve(nums,1,n-1,dp2);

    return max(case1,case2);
    }
};