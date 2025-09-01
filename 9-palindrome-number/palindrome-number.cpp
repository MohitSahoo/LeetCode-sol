class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int orig=x;
        long long y =0;
        
        while(x!=0){
            int z = x% 10;
            x=x/10;
            y = y*10 +z;
            if(y > INT_MAX || y < INT_MIN) return 0;
        }
        if(orig == (int)y){
            return true;
        }else{
            return false;
        }

        
    }
};