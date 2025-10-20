class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        int n = grid.size();
        map <int,int>mpp;
        int repeated=-1;
        int missing =-1;
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
               repeated=i;
            }
            if(mpp[i]==0){
                missing = i;
            }
        }
         
        
        return {repeated,missing};
    }
};