class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> minPrefix(k, LLONG_MAX);  
       
        minPrefix[0]=0;
        long long ans =LLONG_MIN;
        long long curr =0;
        for(int i =0;i<nums.size();i++){
            curr+=nums[i];
            int mod = (i+1)%k;
            if(minPrefix[mod]!=LLONG_MAX){
                ans = max(ans,curr-minPrefix[mod]);
            }
            minPrefix[mod]=min(minPrefix[mod],curr);

        }
        return ans;
    }
};