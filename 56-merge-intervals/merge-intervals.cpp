class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>v1;
        sort(intervals.begin(),intervals.end());
        for(int i =0;i<intervals.size();i++){
            if(v1.empty() || v1.back()[1]<intervals[i][0]){
                v1.push_back(intervals[i]);
            }else{
                v1.back()[1]=max(v1.back()[1],intervals[i][1]);
            }
        }
        return v1;
        
    }
};