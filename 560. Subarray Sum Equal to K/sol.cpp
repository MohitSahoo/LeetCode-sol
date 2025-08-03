class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum =0;
        map <int,int>mpp;
        int count =0;
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
            if(mpp.find(sum - k)!=mpp.end()){
                count+=mpp[sum-k];
            }
            if(sum == k){
                count++;
            }
            mpp[sum]++;
        }
        return count;

        
    }
};
