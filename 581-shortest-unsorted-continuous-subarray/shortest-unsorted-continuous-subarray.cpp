class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = -1, right = -1;
        int maxseen = nums[0];
        for(int i =0;i<nums.size();i++){
            if(nums[i]<maxseen){
                right = i;
               
            }else{
                maxseen = nums[i];
            }
        }
        int minseen= nums[n-1];
        for(int j = nums.size()-2;j>=0;j--){
            if(nums[j]>minseen){
                left = j;
                
            }else{
                minseen = nums[j];
            }
        }
        if(right == -1){
            return 0;
        }

        return (right - left +1);
        
    }
};