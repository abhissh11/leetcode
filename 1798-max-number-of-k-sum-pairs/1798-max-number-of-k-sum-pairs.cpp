class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int opCount = 0;
        int left = 0;
        int right = n-1;
            
        sort(nums.begin(), nums.end());
        while(left<right){
            int sum = nums[left]+nums[right];
            if(sum == k){
                opCount++;
                left++;
                right--;
            }
            else if(sum < k){
                left++;
            }else{
                right--;
            }
        }
    return opCount;
    }
};