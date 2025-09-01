class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(i==0 ){
                    dp[i][j]=matrix[0][j];
                }else{
                int p=INT_MAX;
                int q=INT_MAX;
                int r=INT_MAX;
                if(i>0 && j>0){
                    p =matrix[i][j]+dp[i-1][j-1];
                }
                if(i>0){
                    q=matrix[i][j]+dp[i-1][j];
                }
                if(j+1<n && i>0){
                    r = matrix[i][j]+dp[i-1][j+1];
                }
                dp[i][j] = min({p, q, r});
            }
            }
        }
        return *min_element(dp[m-1].begin(), dp[m-1].end());
        
    }
};