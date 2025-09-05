class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        string s="";
        for(int i =1;i<text1.size()+1;i++){
            for(int j =1;j<text2.size()+1;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int i = text1.size();
        int j = text2.size();
        while(i>0 && j >0){
            if(text1[i-1]== text2[j-1]){
                s.push_back(text1[i-1]);
                i--;j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    s.push_back(text1[i-1]);
                    i--;
                }else{
                    s.push_back(text2[j-1]);
                    j--;
                }
            }
        }
        while(i>0){
                    s.push_back(text1[i-1]);
                    i--;

        }
        while(j>0){
             s.push_back(text2[j-1]);
                    j--;

        }
        reverse(s.begin(),s.end());
        return s;
  
    }
};