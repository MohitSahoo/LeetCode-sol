class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        map<int,int>mpp;
        for(int i =0;i<s.size();i++){
            mpp[s[i]-'a']++;
        }
        for(int i =0;i<t.size();i++){
            mpp[t[i]-'a']--;
            if(mpp[t[i]-'a']==0){
                mpp.erase(t[i]-'a');
            }
        }
        if(mpp.empty()){
            return true;
        }else{
            return false;
        }
        
    }
};