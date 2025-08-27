class Solution {
public: 
    long long func(vector<int>& piles, int mid) {
        long long totalhrs = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalhrs += (long long)ceil((double)piles[i] / (double)mid);
        }
        return totalhrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *std::max_element(piles.begin(), piles.end());
        int ans = high;  // better initialization

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalhrs = func(piles, mid);

            if (totalhrs <= h) {
                ans = mid;
                high = mid - 1;   
            } else {
                low = mid + 1;    
            }
        }
        return ans;
    }
};
