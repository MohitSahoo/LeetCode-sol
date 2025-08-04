class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>sol;
        vector<int>v1(nums.size()+1,0);
        for(int i =0;i<nums.size();i++){
            v1[nums[i]]++;
        }
        for(int i =0;i<v1.size();i++){
            if(v1[i]==0 && i!=0){
                sol.push_back(i);
            }
        }
        return sol;
        
    }
};
