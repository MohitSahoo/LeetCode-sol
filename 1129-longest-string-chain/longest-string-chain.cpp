class Solution {
public:
    
    bool checkstring(const string &s1, const string &s2) {
        if(s1.size() + 1 != s2.size()) return false;

        int i = 0, j = 0;
        while(i < s1.size() && j < s2.size()){
            if(s1[i] == s2[j]) i++, j++;
            else j++; 
        }

        return i == s1.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.size() < b.size();
        });// since here the order of the original array is not important sort it and it becomes a subset sort of a problem

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = n-1; i >= 0; i--) {
            for(int prev = i-1; prev >= -1; prev--) {
                int notTake = dp[i+1][prev+1];
                int take = 0;

                if(prev == -1 || checkstring(words[prev], words[i])) {
                    take = 1 + dp[i+1][i+1];
                }

                dp[i][prev+1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }
};
