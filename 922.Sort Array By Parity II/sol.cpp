class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector <int> vo;
        vector<int>ve;
        for(int i =0;i<nums.size();i++){
            if(nums[i]%2 == 1){
                vo.push_back(nums[i]);
            }else{
                ve.push_back(nums[i]);
            }
        ;}
        for(int i =0;i<nums.size()/2;i++){
            nums[2*i]=ve[i];
            nums[2*i+1]=vo[i];
        }
        return nums;
    }
};
