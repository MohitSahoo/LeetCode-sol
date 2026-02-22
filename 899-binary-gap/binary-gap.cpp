class Solution {
public:
    int binaryGap(int n) {
        string s = bitset<32>(n).to_string();
        int maxlen = 0;
        int last = -1;
        int curr = 0;
        for(int i =0;i<s.size();i++){
            if(s[i]=='1'){
                if(last!=-1){
                    maxlen= max(maxlen ,i-last);
                }
                last = i;
            }
        }
        return maxlen;
        
    }
};