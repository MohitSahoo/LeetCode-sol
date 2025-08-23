class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j =0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        int k = j+1;
        while(k<nums.size()){
            if(nums[j]==0 && nums[k]!=0){
                swap(nums[j],nums[k]);
                j++;
                k++;
            }else{
                k++;
            }

        }
        
        
    }
};