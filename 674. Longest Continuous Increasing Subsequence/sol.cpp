class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int count =1;int maxcount=1;
        for(int i =0;i<nums.size()-1;i++){
            if(nums[i+1]>nums[i]){
                count++;
                if(count>maxcount){
                    maxcount=count;
                }
            }else{
                count =1;
            }
        }
        return maxcount;
        
    }
};
