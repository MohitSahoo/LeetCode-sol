class Solution {
public:
    bool isPalindrome(int x) {
        long long org = x;
        long long rev =0;

        while(x >0){
            int y = x%10;
            rev = rev*10 +y;
            x = x/10;
        }
        if(org == rev){
            return true;
        }
        return false;
        
    }
};