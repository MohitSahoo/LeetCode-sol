class Solution {
public:
    vector<vector<int>>v;
    vector<int>vec;
    void solve(int i ,int sum,int target,vector<int>& candidates){
        int n = candidates.size();
        if(sum > target) return; 
        if(i >= n){
            if(sum == target){
                v.push_back(vec);
            }
            return;
        }
        vec.push_back(candidates[i]);
        solve(i,sum+candidates[i],target,candidates);
        vec.pop_back();
        solve(i+1,sum,target,candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0,0,target,candidates);
       return v;
        
    }
};