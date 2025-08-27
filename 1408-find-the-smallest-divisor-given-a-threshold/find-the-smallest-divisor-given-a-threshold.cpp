class Solution {
public: 
    long long func(vector<int>nums,int mid ){
        long long sum =0;
        for(int i =0;i<nums.size();i++){
            sum += (long long)ceil((double)nums[i] / (double)mid);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low =1;
        int high = *std::max_element(nums.begin(),nums.end());
        int ans =0;
        while(low <= high){
            int mid = (low + high)/2;
            if(func(nums,mid) <= threshold){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};