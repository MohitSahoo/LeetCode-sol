class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum =0;
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum %p ==0){
            return 0;
        }
        int rem = sum %p;
        unordered_map<int,int> mpp;
        mpp[0]=-1;
        int sum1=0;
        int minlen =INT_MAX;
        for(int i =0;i<nums.size();i++){
           sum1 = (sum1+nums[i])%p;// we need to store Modulo Value
            if(sum1 == rem){
                minlen = min(minlen,i+1); 
            }
            int rem1 = (sum1-rem+p)%p;//+p ->to prevent negetive as -3 %p =-3 and let say p =4 then -3+4 %p =1
            if(mpp.find(rem1)!=mpp.end()){
                minlen = min(minlen,i-mpp[rem1]);
            }
            mpp[sum1]=i;
        }
        if (minlen == INT_MAX || minlen == (int)nums.size()) {
            return -1;
        }
        return minlen;
    }
};