class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count =0;
        int max1=0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
                max1=max(count,max1);
            }else{

                count=0;
            }
        }
        return max1;
        
    }
};
