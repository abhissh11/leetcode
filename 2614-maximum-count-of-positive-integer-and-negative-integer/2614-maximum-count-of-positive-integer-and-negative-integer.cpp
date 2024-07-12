class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int posCount = 0;
        int negCount = 0;
        int maxCount = 0;
        for(auto it: nums){
            if(it == 0) continue;
            if(it>0) posCount++;
            if(it<0) negCount++;
            maxCount = max(maxCount, posCount);
            maxCount = max(maxCount, negCount);
        }
        return maxCount;
    }
};