class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest = 1e9;
        for(int i =0;i<nums.size();i++){
            int j = i+1;
            int k = nums.size()-1;
            
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                
                if(abs(sum - target)<abs(closest-target)){
                    closest = sum;
                }else if(sum < target){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return closest;
        
    }
};