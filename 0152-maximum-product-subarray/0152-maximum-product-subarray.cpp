class Solution {
public:
    int maxProduct(vector<int>& nums) {
         double ans=INT_MIN;
        double prod=1;
        int pc=0,nc=0,i=0;
        while(i<nums.size()){
            int j=i;
            while(j<nums.size() && nums[j]!=0){
                if(nums[j]>0)pc++;
                else nc++;
                prod*=nums[j];
                ans=max(ans,prod);
                j++;
            }
            if(j<nums.size())ans=max(ans,(double)0);
            if(nc&1){
                while(i<j && (nc&1)){
                    if(nums[i]<0)nc--;
                    prod/=nums[i++];
                }
                if(i<j)ans=max(ans,prod);
            }
            i=j+1;prod=1;
        }
        return ans;
    }
};