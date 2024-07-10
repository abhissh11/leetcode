// Given an array check if the the array is sorted and rotated
// Ex: Input: nums = [3,4,5,1,2]    Output: true
// Input: nums = [2,1,3,4]   Output: false

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size(), count = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                count++;
                // in the same iteration check
                if (nums[n - 1] > nums[0])
                    count++;
            }
        }

        return count <= 1;
    }
};