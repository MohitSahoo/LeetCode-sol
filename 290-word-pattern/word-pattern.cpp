class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>words;
        stringstream ss(s);
        string word;

        while(ss>>word){
            words.push_back(word);
        }
        if(pattern.size()!= words.size()){
            return false;
        }
        map <char,string>mpp1;
        map <string,char>mpp2;

        for(int i =0;i<pattern.size();i++){
            char w = pattern[i];
            string t = words[i];

            if(mpp1.find(w)!=mpp1.end() && mpp1[w]!=t){
                return false;
            }
            if(mpp2.find(t)!=mpp2.end() && mpp2[t]!=w){
                return false;
            }
            mpp1[w]=t;
            mpp2[t]=w;
        }
        return true;
        
    }
};