class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int j =0;
    int i =0;
    while(j<nums.size()){
        
        if(nums[i]!=nums[j]){
            nums[i+1]=nums[j];
            i++;
            
        }
        j++;

    }
    return i+1;
    }
        
    
};