class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        map <int,int>mpp;
        int maxlen =0;
        int sum =0;
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
            int rem = sum-k;
            if(mpp.find(rem)!=mpp.end()){
                maxlen = max(maxlen,i-mpp[rem]);
            }
            if(mpp.find(sum)==mpp.end()){
                mpp[sum]=i;
            }

        }
        return maxlen;
        
    }
};
