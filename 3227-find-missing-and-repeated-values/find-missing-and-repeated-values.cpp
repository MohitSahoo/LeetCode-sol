class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans;
        int n = grid.size();
        map <int,int>mpp;
        for(int i =1;i<=n*n;i++){
            mpp[i]=0;
        }
        for(int i =0;i<n;i++){
            for(int j = 0;j<n;j++){
                mpp[grid[i][j]]++;
            }

        }
        for(int i =1;i<=n*n;i++){
            if(mpp[i]>1){
                ans.push_back(i);
            }
        }
         for(int i =1;i<=n*n;i++){
            if(mpp[i]==0){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};