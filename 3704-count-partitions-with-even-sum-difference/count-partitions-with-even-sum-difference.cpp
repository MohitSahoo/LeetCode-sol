class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long sum =0;
        for(int i =0;i<nums.size();i++){
            sum += nums[i];
        }
        if( nums.size()<0){
            return 0;
        }
        if(sum % 2 ==0){
            return nums.size()-1;
        }else{
            return 0;
        }
        
    }
};