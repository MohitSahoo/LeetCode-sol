class Solution {
public:
    int smallestRepunitDivByK(int k) {
    int n = 1;
    if( n % 2 == 0 || n % 5 ==0){
        return -1;
    }
    int rem = 0;
    for(int i =1;i<=k;i++){
        rem = (rem * 10 +1)%k;
        if(rem == 0){
            return i;
        }
    }
    return -1;

    }
};