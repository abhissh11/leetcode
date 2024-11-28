class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        for(int i=0; i<nums.size(); i++){
            int pivot = i;
            int rightSum = totalSum - leftSum - nums[pivot];
            if(rightSum == leftSum){
                return pivot;
            }
            leftSum += nums[pivot];
        }
        return -1;
    }
};