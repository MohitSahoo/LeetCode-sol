class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){
            return 0;
        }
        vector<int>hash(256,-1);
        int n = s.size();
        int l =0;
        int r = 0;
        int maxlen = -1;
        while(r<n){
            
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l = hash[s[r]]+1;
                }
            }
            if(maxlen <r-l+1){
                maxlen = r-l+1;
            }
            hash[s[r]]=r;
            r++;
            
        }
        return maxlen;
        
    }
};