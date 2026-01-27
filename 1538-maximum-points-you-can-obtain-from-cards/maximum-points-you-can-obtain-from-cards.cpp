class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int l = k-1;
        int lsum =0;
        int rsum =0;
        int maxsum = INT_MIN;
        int r = arr.size()-1;
        for(int i =0;i<k;i++){
            lsum +=arr[i];
        }
        maxsum = lsum;
        for(int i=k-1;i>=0;i--){
            lsum -=arr[i];
            rsum+=arr[r];
            r--;
            maxsum = max(maxsum,lsum + rsum);
        }
        return maxsum;

        
    }
};