class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        double prdt = 1;
        if(n < 0){
            N = -N;
            x = 1/x;
        }
        while(N >0){
        if( N % 2 ==0){
            x = x*x;
            N = N/2;

        }
        else{
            prdt = prdt *x;
            N = N-1;
        }
        }
        return prdt;


        
    }
};