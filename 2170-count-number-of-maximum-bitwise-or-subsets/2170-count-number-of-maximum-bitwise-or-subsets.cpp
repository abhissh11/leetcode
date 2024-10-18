class Solution {
    int solve(int i, int ors, int maxm, vector<int>& nums){
        if(i >= nums.size()){
            //if OR of the curr subset equals the maximum OR, count it
            return (ors == maxm)? : 0;
        }
            // include the curr elm in the subset OR
        int count = 0;
        count += solve(i+1, ors | nums[i], maxm, nums);

        //exclude the curr elem from the subset OR
        count += solve(i + 1, ors, maxm, nums);

        return count;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        // The problem involves finding the number of subsets in 
        // which the bitwise OR of all elements equals the maximum possible 
        // OR of the entire array. The first intuition is to generate all subsets
        //  and compute their OR values, then compare each subset's OR value with
        //   the maximum OR that can be achieved by considering all elements in the array.
   
   //calculate the max OR value from all elms
   int maxm = 0;
        for(auto x: nums){
            maxm |= x;
        }
        //start recursion from first elm with OR=0
        return solve(0, 0, maxm, nums);
    }
};