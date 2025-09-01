class Solution {
public:
    bool isPalindrome(int x) {
        std::string y = std::to_string(x);
        int n = y.size();
        int i = 0;
        int j = n-1;
        while(i<=j){
            if(y[i]!=y[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;

        
    }
};