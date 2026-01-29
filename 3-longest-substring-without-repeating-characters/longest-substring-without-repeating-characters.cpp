class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int maxlen = 0;
        vector<int>mpp(256,-1);
        while(r<n){
            if(mpp[s[r]]!=-1){
                if(mpp[s[r]]>=l){
                    l = mpp[s[r]]+1;

                }
            }
            if(r-l+1 >maxlen){
                maxlen = r-l+1;
            }
            mpp[s[r]]=r;
            r++;
        }
        return maxlen;
        
    }
};