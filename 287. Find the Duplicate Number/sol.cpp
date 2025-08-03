class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i =0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto& nums:mpp){
            if(nums.second > 1){
                return nums.first;
            }
        }
        return -1;
        
    }
};
