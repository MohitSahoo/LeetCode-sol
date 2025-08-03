class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i =0;i<nums.size();i++){
            if(nums[i]==0){
                nums[i]=-1;
            }
        }
        map <int,int> mpp;
        int sum =0;
        int maxlen =0;
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
            mpp[0] = -1;
            if(mpp.find(sum)!= mpp.end()){
                int len = i - mpp[sum];
                if(len > maxlen){
                    maxlen = len;
                }
            }
            if(mpp.find(sum)==mpp.end()){
            mpp[sum]=i;
            } 
        }
        return maxlen;
        
    }
};
