class Solution {
public:
    int reverse(int x) {
        long long y =0;
        while(x!=0){
            int z = x% 10;
            x=x/10;
            y = y*10 +z;
            if(y > INT_MAX || y < INT_MIN) return 0;
        }
        return y;
        
    }
};