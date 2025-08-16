class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
       
            for(int j =0;j<n;j++){
                dp[0][j] = matrix[0][j];            
                }
        
        for(int i =1;i<m;i++){
            for(int j = 0;j<n;j++){
                int p = 1e8;
                int q = 1e8;
                int r = 1e8;

                if(j>0){
                    p = matrix[i][j]+dp[i-1][j-1];

                }

                q=matrix[i][j]+dp[i-1][j];

                if(j+1<n){
                    r = matrix[i][j]+dp[i-1][j+1];
                }
                dp[i][j] = std::min({p, q, r});

                
            }
            
        }
        return *min_element(dp[m-1].begin(),dp[m-1].begin()+n);
        
    }
};
