class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>v;
        vector<int>p;
        vector<int>n;
        for(int i =0;i<nums.size();i++){
            if(nums[i]<0){
                n.push_back(nums[i]);
            }else{
                p.push_back(nums[i]);
            }
        }
        for(int i =0;i<n.size();i++){
            v.push_back(p[i]);
            v.push_back(n[i]);
        }
        return v;
        
    }
};