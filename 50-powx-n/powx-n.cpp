class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(n<0){
            x= 1/x;
            N =-N;
        }
        double prdt =1;
        while(N >0){
        if(N % 2 ==1){
            prdt = prdt *x;
            N= N-1;
        }else{
            x= x*x;
            N= N/2;
        }
        }
        return prdt ;
        
    }
};