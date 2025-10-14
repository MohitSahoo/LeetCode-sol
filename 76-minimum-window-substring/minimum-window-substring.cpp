class Solution {
public:
    string minWindow(string s, string t) {
        vector <int> hash(256,0);
        int l = 0;
        int r = 0;
        for (int i =0;i<t.size();i++){
            hash[t[i]]++;
        }  
        int minlen = INT_MAX;
        int sindex = -1;
        int count =0;

        while(r<s.size()){
            if(hash[s[r]]>0){
                count = count+1;
            }
            hash[s[r]]--;
            while(count == t.size()){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    sindex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    count--;
                }
                l++;
            }
            r++;
        }
        if(sindex == -1){
            return "";
        }
        return s.substr(sindex,minlen);
    }
};