class Solution {
public:
    int climbStairs(int n) {
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        int prev2=1;
        int prev1=2;
        for(int i=3;i<n+1;i++){
            int curri = prev2+prev1;
            prev2 = prev1;
            prev1= curri;
        }
        return prev1;
        
    }
};
