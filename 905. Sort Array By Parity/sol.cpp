class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j =0;
        for(int i =0;i<nums.size();i++){
            if(nums[i] % 2 == 1){
                j=i;
                break;
            }
        }
        int k = j+1;
        while(k<nums.size()){
            if(nums[k]% 2 == 0 && nums[j]%2 ==1 ){
                swap(nums[j],nums[k]);
                j++;
            }
            k++;
        }
        return nums;
        
    }
};
