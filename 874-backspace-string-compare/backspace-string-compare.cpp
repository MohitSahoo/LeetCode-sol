class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return strings(s) == strings(t);
        
    }
    string strings(string s){
        string st;
        for(int i =0;i<s.size();i++){
            if(s[i]=='#'){
                if(st.size()!=0){
                    st.pop_back();
                }
            }else{
                st.push_back(s[i]);
            }
        }
        return st;

    }
};