class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l =0;
        int r = 0;
        int maxlen = 0;
        vector<int>v(256,-1);
        while(r<s.size()){
            
            if(v[s[r]]!=-1){
                if(v[s[r]]>=l){
                    l = v[s[r]]+1;
                }
            }
            if(maxlen < r-l+1){
                maxlen = r-l+1;
            }
            v[s[r]]=r;
            r++;
        }
        return maxlen;

        
    }
};