class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int start = 0;
        int end = nums.size()-1;

       while(start < end){
       if((nums[start])+(nums[end])<target)
        {
            count +=(end-start);
            start++;
        }
        else{
            end--;
        }
       }
       return count;
    }
};