class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        std::sort(nums.begin(),nums.end());
        long long total =0;
        int left =0;
        int maxfreq=0;
        for(int right =0;right<nums.size();right++){
            total +=nums[right];
            long long cost = 1LL*nums[right]*(right-left+1)-total;
            if(cost >k){
                while(cost > k){
                    total-=nums[left];
                    left++;
                    cost = 1LL * nums[right] * (right - left + 1) - total;
                }
            }
            maxfreq=max(maxfreq,right-left+1);

        }
        
        return maxfreq;
        
    }
};
