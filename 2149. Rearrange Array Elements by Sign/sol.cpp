class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>v1;
        vector<int>vp;
        vector<int>vn;
        for(int i =0;i<nums.size();i++){
            if(nums[i]>=0){
                vp.push_back(nums[i]);
            }else{
                vn.push_back(nums[i]);
            }
        }
        for(int i =0;i<vp.size();i++){
            v1.push_back(vp[i]);
            v1.push_back(vn[i]);
        }
        return v1;
        
    }
};
