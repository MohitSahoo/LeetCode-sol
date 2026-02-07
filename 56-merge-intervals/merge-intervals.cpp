class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>v1;
         sort(intervals.begin(),intervals.end());
        v1.push_back(intervals[0]);
        for(int i =1;i<intervals.size();i++){
            if(v1.back()[1]>=intervals[i][0]){
                v1.back()[1]=max(v1.back()[1],intervals[i][1]);
            }else{
                v1.push_back(intervals[i]);
            }
        }
        return v1;
        
    }
};