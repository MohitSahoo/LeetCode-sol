class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()== 0){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }
        int prev2 = nums[0];
        int prev1 = max(nums[0],nums[1]);
        for(int i =2;i<nums.size();i++){
            int take = prev2 + nums[i];
            int no = 0+ prev1;
            int cur= max(take,no);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};