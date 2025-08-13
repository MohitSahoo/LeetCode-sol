class Solution {
public:
    int rob(vector<int>& nums) {
        int prev =nums[0];
        int prev2 = 0;
        int take =0;
        int nottake=0;
        for(int i =1;i<nums.size();i++){
            take = nums[i];
            if(i>1){
                take+=prev2;
            }
            nottake = 0 + prev;
            int curri = max(take,nottake);
            prev2 = prev;
            prev=curri;
        }
        return prev;
        
    }
};
